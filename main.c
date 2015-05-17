#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
#include "logica.h"

//compile as gcc main.c -lm -o main - usar lm para detectar las bibliotecas
struct VECTOR vector1 = {1.0, 1.0, 1.0};
struct VECTOR vector2 = {1.0, 1.0, 1.0};
	
int main(int argc, char* argv[])
{
int vres = 600;
int hres = 600;
int Xmin = -100;
int Ymin = -100;
int Xmax =  100;
int Ymax =  100;
double Xw;
double Yw;
double Zw;
double Xe = 0.0;
double Ye = 0.0;
double Ze = 0.0;
double L = 0.0;
double Xd;
double Yd;
double Zd;

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
vector1 = vectorMasVector(vector1, vector2);
printf("%Lf",vector1.elementos[0]);
printf("%s\n","Esto es una prueba");
return 1;	
	}
