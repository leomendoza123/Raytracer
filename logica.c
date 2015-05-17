#include <math.h>
#include "logica.h"
//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza

double xToFramePoint(int xp, int hres, int xmax, int xmin){
	double xResult;
	xResult = ((xp + (1/2)) * ((double) (xmax - xmin) / (double) hres)) + xmin;
	return xResult;
	}

double yToFramePoint(int yp, int vres, int ymax, int ymin){
	double yResult;
	yResult = ((yp + (1/2)) * ((double) (ymax - ymin) / (double) vres)) + ymin;
	return yResult;
	}

double getL(double xw, double yw, double zw, double xe, double ye, double ze){
	double lResult;
	lResult = (sqrt(pow((xw - xe),2)) + sqrt(pow((yw-ye),2)) + sqrt(pow((zw-ze),2)));
	return lResult;
	}

double getXd(double xw, double xe, double l){
	double XdResult;
	XdResult = (double) (xw - xe) / (double) l;
	return XdResult;
	}

double getYd(double yw, double ye, double l){
	double YdResult;
	YdResult = (double) (yw - ye) / (double) l;
	return YdResult;
	}

double getZd(double zw, double ze, double l){
	double ZdResult;
	ZdResult = (double) (zw - ze) / (double) l;
	return ZdResult;
	}
