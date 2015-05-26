
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vectorlib.h"
#include "structs.h"


#include "diseno.h"
#include "logica.h"



#include "main.h"
#include "MESA.h"


//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//compile as gcc main.c vectorlib.c logica.c print.c -lm -o main



int main(int argc, char* argv[]);
RGB De_que_color ( Ray Rayo);
int First_Intersection ( Ray Rayo, INTERSECTION *interseccion );
int HayInterseccion(Ray *rayo, ESFERA *esfera, double *distancia);
VECTOR PuntoInterseccion (Ray Rayo, double distancia);
 VECTOR DireccionNormalizada (VECTOR Destino, VECTOR Origen );

void cargaBuffer ();
void escribirAvs();

int main(int argc, char* argv[])
        {
        W_HEIGHT = 500;
        W_WIDTH = 500;

        //Inicia GLUT
        glutInit(&argc, argv);
        //Inicia el buffer
        BufferInit();
        cargaBuffer();
        escribirAvs();
        init();

        //
        //FUNCION_MAGICA_QUE_GUARDA_AVSs(BUFFER);  ///<<<<<<<<<<AQUI

       // cargaBuffer ();
    }


void escribirAvs(void){
FILE *fp;

int i;
int j;
int x = (int)W_HEIGHT;
int y = (int)W_WIDTH;
int r;
int g;
int b;
char *charR = "";
char *charG = "";
char *charB = "";
fp = fopen("imagen.avs","w");
 if(fp == NULL){
  printf("No se pudo crear el archivo para la imagen");
 }
 else{
  fprintf(fp,"# ImageMagick pixel enumeration: %d,%d,255,rgb\n", y,x);
  for(i=0; i<x; ++i){
   for(j=0; j<y; ++j){
       r = 250*BUFFER[i][j].R;
       g = 250* BUFFER[i][j].G;
       b = 250 *BUFFER[i][j].B;
       charR ="";
       charG ="";
       charB="";
       if(r<=15){charR="0";}
       if(g<=15){charG="0";}
       if(b<=15){charB="0";}
       fprintf(fp,"%d,%d: (%d,%d,%d)  #%s%X%s%X%s%X  rgb(%d,%d,%d)\n",j,i,r,g,b,charR,r,charG,g,charB,b,r,g,b);
       }
  }
fclose(fp);
printf("\n\nlisto imagen.avs");
 }

}

void cargaBuffer (void){

        printLabelEncabezado();
        int vres = 500;
        int hres = 500;
        int Xmin =  0 ;
        int Ymin =  0;
        int Xmax =  500;
        int Ymax =  500;
        double Xw = 0;
        double Yw = 0;
        double Zw = 0;
        double Xe =   250;
        double Ye =   250;
        double Ze =  -1500;
        double L;
        double Xd = 0;
        double Yd = 0;
        double Zd = 0;

        int i =0;
        int j =0;

        RGB Color;
        for(i=0; i < hres; i++){
                   //printf (">>>::Cambio de linea #%d :::<< \n", i);
                    for(j=0; j < vres; j++){

                    // Puntos en framebuffer
                    Xw = WindowPointToFramePoint( i,  hres,  Xmax,  Xmin);
                    Yw = WindowPointToFramePoint( j,  vres,  Ymax,  Ymin);
                    Zw = 0.0;


                    // Direccion del rayo normalizada
                    L  = getL (Xw,Yw,Zw,Xe,Ye,Ze);
                    Xd = getXd(Xw, Xe, L);
                    Yd = getYd(Yw, Ye, L);
                    Zd = getZd(Zw, Ze, L);


                    Ray Rayo;
                    //Rayo.direccion.x = Xd;
                    //Rayo.direccion.y = Yd;
                    //Rayo.direccion.z = Zd;
                    VECTOR PuntoVentana = {Xw, Yw, Zw};
                    VECTOR Ojo = {Xe, Ye, Ze};
                    Rayo.direccion = DireccionNormalizada (PuntoVentana,Ojo);
                    Rayo.origen.x = Xe;
                    Rayo.origen.y = Ye;
                    Rayo.origen.z = Ze;

                    // Color del pixel;
                    Color = De_que_color (Rayo);
                    plot ( i,  j,  Color);

                    }
        }
}

RGB De_que_color (Ray Rayo)
{
    RGB color;

    INTERSECTION  interseccion;
    if (First_Intersection(Rayo, &interseccion) == 1){

        //printf ("%f, %f, %f __ <<\n", interseccion.puntoInterseccion.x, interseccion.puntoInterseccion.y, interseccion.puntoInterseccion.z);

        VECTOR N = DireccionNormalizada(interseccion.puntoInterseccion, interseccion.esfera.punto );

       // printf ("Normal: %f, %f, %f __ \n", N.x, N.y, N.z);

        double iluminacion = 0;
        unsigned int numLuces = sizeof(listaLuces)/sizeof(listaLuces[0]);
        int x;
        VECTOR L;
        for (x = 0; x< numLuces; x++){
            //printf ("%f, %f, %f __[[\n", interseccion.puntoInterseccion.x, interseccion.puntoInterseccion.y, interseccion.puntoInterseccion.z);


            L = DireccionNormalizada (listaLuces[x].origen, interseccion.puntoInterseccion);
            //printf ("DirLuz: %f, %f, %f __\n", L.x, L.y, L.z);

            iluminacion += (vectorProductoPunto(N, L) * interseccion.esfera.KD * listaLuces[x].Ip) + (Ka * Ia);
            
            if(iluminacion > 1.0){
				iluminacion = 1.0;
				} 
            //printf ("Iluminacion: %f \n", iluminacion);

        }

    //return interseccion.esfera.color;
        RGB color;
        color.B =  (double)interseccion.esfera.color.B*iluminacion;
        color.G =  (double)interseccion.esfera.color.G*iluminacion;
        color.R =  (double)interseccion.esfera.color.R*iluminacion;
        return color;
        //return EscalarColor(interseccion.esfera.color, iluminacion) ;
    }
    else {

        return BACKGROUD;
    }
}


int First_Intersection (Ray Rayo, INTERSECTION *interseccionEcontrada)
         {

                INTERSECTION  interseccion;
                interseccion.distancia = 0;

                double tmin = 5000;
                int numEsferas = sizeof(listaEsferas)/sizeof(listaEsferas[0]);
                int x;
                int existeInterseccion;
                double *distanciaConPrimeraInterseccion = 0;

                for (x=0; x < numEsferas; x++){
                    double distancia;
                    ESFERA Esfera = listaEsferas[x];
                     existeInterseccion = HayInterseccionConEferas (&Rayo, &Esfera, &distancia);
                     if (existeInterseccion){
                        interseccion.distancia = distancia; //TODO: Revisar que sea primera interseccion
                        interseccion.esfera = Esfera;
                     }
                }
                if (interseccion.distancia != 0 ){
                    interseccion.puntoInterseccion = PuntoInterseccion (Rayo, interseccion.distancia);
                    *interseccionEcontrada = interseccion;
                    return 1;
                }
                else {

                    return 0;
                }
        }
VECTOR PuntoInterseccion (Ray Rayo, double distancia){
   //printf ("Rayo Direc; %f, %f, %f\n", Rayo.direccion.x, Rayo.direccion.y, Rayo.direccion.z);
    //printf ("Rayo Orig; %f, %f, %f\n", Rayo.origen.x, Rayo.origen.y, Rayo.origen.z);
    //printf ("Distancia; %f\n", distancia);
    VECTOR punto = vectorSuma(Rayo.origen, vectorMultiplicacion(Rayo.direccion, distancia));
    //printf ("Punto I: %f, %f, %f \n\n", punto.x, punto.y, punto.z);
    return punto;

}

int HayInterseccionConEferas(Ray *rayo, ESFERA *esfera, double *distancia)
    {
    Ray ray = *rayo;
   // printf (">>>%f,%f,%f<< \n",  ray.direccion.x,  ray.direccion.y,  ray.direccion.z);

    double a = vectorProductoPunto(rayo->direccion, rayo->direccion);
    VECTOR ro_sc = vectorResta(rayo->origen, esfera->punto);
    double b = 2.0 * vectorProductoPunto(rayo->direccion, ro_sc);
    double y = vectorProductoPunto(ro_sc, ro_sc) - (esfera->radio*esfera->radio) ;


    double discriminante = b*b - 4 * a * y;

    double RaizDiscriminante = sqrt(b*b - 4 * a * y);

    if (discriminante >=0 ){
        double t1 = (-b-RaizDiscriminante)/2*a;
        double t2 = (-b+RaizDiscriminante)/2*a;
        if (t1<t2){
            *distancia =  t1;
        }
        else{
            *distancia =  t2;
        }
        return 1;
    }
    else {
        return 0;
    }

    }



/// REUBICAR

 VECTOR DireccionNormalizada (VECTOR Destino, VECTOR Origen ){

                        double L =  getL (Destino.x,Destino.y,Destino.z,Origen.x,Origen.y,Origen.z);
                        VECTOR direccion;
                        direccion.x = (double)getXd(Destino.x, Origen.x, L); // TODO: Usar una sola funccion
                        direccion.y = (double)getYd(Destino.y, Origen.y, L);
                        direccion.z = (double)getZd(Destino.z, Origen.z, L);




                        return direccion;
}

