#include <stdio.h>
#include <math.h>
#include "vectorlib.h"

struct VECTOR vectorMasVector(struct VECTOR vector1, struct VECTOR vector2){
	struct VECTOR vectorResult;
	int i=0;
	for (i=0; i < 3; i++){
		vectorResult.elementos[i] = vector1.elementos[i] + vector2.elementos[i];
		}
	return vectorResult;
	}

struct VECTOR vectorMasEntero(struct VECTOR vector, int escalar){
	struct VECTOR vectorResult;
	int i=0;
	for (i=0; i<3; i++){
		vectorResult.elementos[i] = vector.elementos[i] + escalar;
		}
	return vectorResult;
	}
	
struct VECTOR vectorMasLongDouble(struct VECTOR vector, long double escalar){
	struct VECTOR vectorResult;
	int i=0;
	for(i=0; i<3; i++){
		vectorResult.elementos[i] = vector.elementos[i] + escalar;
		}
	return vectorResult;
	}
