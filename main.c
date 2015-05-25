#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
#include "logica.h"
#include "diseño.h"
#include <math.h>

//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//compile as gcc main.c vectorlib.c logica.c print.c -lm -o main

void De_que_color ( Ray Rayo);
INTERSECTION First_Intersection ( Ray Rayo);


int main(int argc, char* argv[])
        {
        printLabelEncabezado();
        int vres = 10;
        int hres = 10;
        int Xmin =  0 ;
        int Ymin =  0;
        int Xmax =  10;
        int Ymax =  10;
        double Xw = 0;
        double Yw = 0;
        double Zw = 0;
        double Xe =   5.0;
        double Ye =   5.0;
        double Ze =  -6.0;
        double L;
        double Xd = 0;
        double Yd = 0;
        double Zd = 0;

        int i =0;
        int j =0;
        for(i=0; i < hres; i++){
                    printf (">>>::Cambio de linea #%d :::<< \n", i);
                    for(j=0; j < vres; j++){

                    // Puntos en framebuffer
                    Xw = xToFramePoint( i,  hres,  Xmax,  Xmin);
                    Yw = yToFramePoint( j,  vres,  Ymax,  Ymin);
                    Zw = 0.0;


                    // Direccion del rayo normalizada
                    L  = getL (Xw,Yw,Zw,Xe,Ye,Ze);
                    Xd = getXd(Xw, Xe, L);
                    Yd = getYd(Yw, Ye, L);
                    Zd = getZd(Zw, Ze, L);
                    Ray Rayo;
                    Rayo.direccion.x = Xd;
                    Rayo.direccion.y = Yd;
                    Rayo.direccion.z = Zd;
                    Rayo.origen.x = Xe;
                    Rayo.origen.y = Ye;
                    Rayo.origen.z = Ze;

                    // Toda el color del rayo
                    De_que_color (Rayo);



                    printf (">>>%g,%g<< ___", Xw, Yw);
                    printf (">>>%f,%f,%f<< \n",  Rayo.direccion.x,  Rayo.direccion.y,  Rayo.direccion.z);

                    }
        }


        //printf("%d", vector1);

       /* vector1 = vectorPlusVector(vector1, vector2);
        printf("%Lf",vector1.element[0]);
        printf("%s","\nEsto es una prueba");
        return 1;
        */
    }



void De_que_color (Ray Rayo)
{
    RGB color;

    INTERSECTION  interseccion;
    interseccion = First_Intersection(Rayo);

    //if (!interseccion)
    //color = BACKGROUND;
    //else:
    //color = interseccion -> objeto.color;
    //return color;
}




INTERSECTION First_Intersection (Ray Rayo)
         {

                INTERSECTION  interseccion;
                double tmin = 5000;
                int numEsferas = sizeof(listaEsferas)/sizeof(listaEsferas[0]);
                int x;
                int existeInterseccion;
                double *distanciaConPrimeraInterseccion = 0;

                for (x=0; x < numEsferas; x++){
                    double *distancia;
                    ESFERA Esfera = listaEsferas[x];
                     existeInterseccion = IntersecionConEspera (&Rayo, &Esfera, distancia);
                     if (existeInterseccion){
                        interseccion.distancia = *distancia; //TODO: Revisar que sea primera interseccion
                     }
                }
                return (interseccion);
        }

int IntersecionConEspera(Ray *rayo, ESFERA *esfera, double *distancia)
    {
    Ray ray = *rayo;
    printf (">>>%f,%f,%f<< \n",  ray.direccion.x,  ray.direccion.y,  ray.direccion.z);

    double a = vectorProductPoint(rayo->direccion, rayo->direccion);
    VECTOR ro_sc = vectorResta(rayo->origen, esfera->punto);
    double b = 2.0 * vectorProductPoint(rayo->direccion, ro_sc);
    double y = vectorProductPoint(ro_sc, ro_sc) - (esfera->radio*esfera->radio) ;
    if (b < 0) {
        int tt = 0;
    }
    double discriminante = b*b - 4 * a * y;
    double distSqrt = discriminante*discriminante;
    double q = b < 0.0 ? (-b - distSqrt) / 2.0 : (-b + distSqrt) / 2.0;
    double t0 = q / a;
    double t1 = y / q;
    if (t0 > t1) {
        double swap = t0;
        t0 = t1;
        t1 = swap;
    }
    if (t1 < 0) {
        return 0;
    } else if(t0 < 0) {
        *distancia = t1;
    } else {
        *distancia = t0;
    }
    return 1;

    }


