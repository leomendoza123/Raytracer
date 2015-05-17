#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
#include "logica.h"
//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//compile as gcc main.c -lm -o main - usar lm para detectar las bibliotecas
struct VECTOR vector1 = {1.0, 1.0, 1.0};
struct VECTOR vector2 = {1.0, 1.0, 1.0};
	
int main(int argc, char* argv[])
{
printLabelEncabezado();
int vres = 600;
int hres = 600;
int Xmin = -100;
int Ymin = -100;
int Xmax =  100;
int Ymax =  100;
long double Xw;
long double Yw;
long double Zw;
long double Xe = 0.0;
long double Ye = 0.0;
long double Ze = 0.0;
long double L = 0.0;
long double Xd;
long double Yd;
long double Zd;

int i =0;
int j =0;
for(i=0; i < hres; i++){
	for(j=0; j < vres; j++){
	Xw = xToFramePoint(i,hres,Xmax,Xmin); 
	Yw = yToFramePoint(j,vres,Ymax,Ymin);  
	Zw = 0.0;
	 L = getL(Xw,Yw,Zw,Xe,Ye,Ze);
	Xd = getXd(Xw, Xe, L);
	Yd = getYd(Yw, Ye, L);	
	Zd = getZd(Zw, Ze, L);
	
	}
}
vector1 = vectorPlusVector(vector1, vector2);
printf("%Lf",vector1.element[0]);
printf("%s","\nEsto es una prueba");
return 1;	
	}
