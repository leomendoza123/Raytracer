#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
//Instituto Tecnologico de Costa Rica
//Introduccion a los graficos por computadora
//Jose Carlos Alvarez Umana
//Leonardo Mendoza
//Esta biblioteca esta diseñada para vectores de 3 elementos

long double getMagnitude(struct VECTOR vector){
	long double result;
	result = sqrt(pow(vector.element[0],2) + pow(vector.element[1],2) + pow(vector.element[2],2));
	return result;
	}

struct VECTOR getNormalizedVector(struct VECTOR vector){
	long double vectorMagnitude = getMagnitude(vector);
	struct VECTOR vectorResult;
	int i = 0;
	for (i=0; i<3; i++){
		vectorResult.element[i] = vector.element[i] * ((long double) 1/ (long double) vectorMagnitude);
		}
	return vectorResult;
	}

long double vectorXvector(struct VECTOR vector1, struct VECTOR vector2){
	long double result = 0.0;
	int i=0;
	for (i=0; i<3; i++){
		result = result + (vector1.element[i] * vector2.element[i]);
		}
	return result;
	}
	
struct VECTOR vectorPlusVector(struct VECTOR vector1, struct VECTOR vector2){
	struct VECTOR vectorResult;
	int i=0;
	for (i=0; i < 3; i++){
		vectorResult.element[i] = vector1.element[i] + vector2.element[i];
		}
	return vectorResult;
	}

struct VECTOR vectorPlusEntero(struct VECTOR vector, int escalar){
	struct VECTOR vectorResult;
	int i=0;
	for (i=0; i<3; i++){
		vectorResult.element[i] = vector.element[i] + escalar;
		}
	return vectorResult;
	}
	
struct VECTOR vectorPlusLongDouble(struct VECTOR vector, long double escalar){
	struct VECTOR vectorResult;
	int i=0;
	for(i=0; i<3; i++){
		vectorResult.element[i] = vector.element[i] + escalar;
		}
	return vectorResult;
	}
