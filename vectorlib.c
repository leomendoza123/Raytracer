#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
#include "print.h"
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

int isVectorUnitary(struct VECTOR vector){
	long double vectorMagnitude = getMagnitude(vector);
	if(vectorMagnitude == 1.0){
		return 1; //si es unitario
		}
		else{
			return 0; //no es unitario
			}
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

struct VECTOR vectorDividedByInteger(struct VECTOR vector, int escalar){
	
	if(escalar == 0){
		struct VECTOR vectorResult;
		printLabelError3();
		vectorResult = vector;
		return vectorResult;
		}
	else{
		int i = 0;
		struct VECTOR vectorResult;
		for (i=0; i<3; i++){
			vectorResult.element[i] = vector.element[i] * ((int) 1 / (int)escalar);
			}
			return vectorResult;
		}
	}

struct VECTOR vectorDividedByLongDouble(struct VECTOR vector, long double escalar){
	
	if(escalar == 0.0){
		struct VECTOR vectorResult;
		printLabelError3();
		vectorResult = vector;
		return vectorResult;
		}
	else{
		int i = 0;
		struct VECTOR vectorResult;
		for(i=0; i<3; i++){
			vectorResult.element[i] = vector.element[i] * ((long double) 1 / (long double) escalar);
			}
			return vectorResult;
		}
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

struct VECTOR vectorPlusInteger(struct VECTOR vector, int escalar){
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
