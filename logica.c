#include <math.h>
#include "logica.h"
//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza

long double xToFramePoint(int xp, int hres, int xmax, int xmin){
	long double xResult;
	xResult = ((xp + (1/2)) * ((long double) (xmax - xmin) / (long double) hres)) + xmin;
	return xResult;
	}

long double yToFramePoint(int yp, int vres, int ymax, int ymin){
	long double yResult;
	yResult = ((yp + (1/2)) * ((long double) (ymax - ymin) / (long double) vres)) + ymin;
	return yResult;
	}

long double getL(long double xw, long double yw, long double zw, long double xe, long double ye, long double ze){
	long double lResult;
	lResult = (sqrt(pow((xw - xe),2)) + sqrt(pow((yw-ye),2)) + sqrt(pow((zw-ze),2)));
	return lResult;
	}

long double getXd(long double xw, long double xe, long double l){
	long double XdResult;
	XdResult = (long double) (xw - xe) / (long double) l;
	return XdResult;
	}

long double getYd(long double yw, long double ye, long double l){
	long double YdResult;
	YdResult = (long double) (yw - ye) / (long double) l;
	return YdResult;
	}

long double getZd(long double zw, long double ze, long double l){
	long double ZdResult;
	ZdResult = (long double) (zw - ze) / (long double) l;
	return ZdResult;
	}
