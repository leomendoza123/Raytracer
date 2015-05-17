#include <stdio.h>
#include <math.h>
#include "vectorlib.h"
/*
long double  vectormasvector(long double vector1[], long double vector2[]){
    int i = 0;
    long double vectorResult[3];
    for (i=0; i < 3; i++){
		vectorResult[i] = vector1[i] + vector2[i];
		}
	return *vectorResult;
	}
*/

struct VECTOR vectormasvector(struct VECTOR vector1, struct VECTOR vector2){
	struct VECTOR vectorResult;
	int i=0;
	for (i=0; i < 3; i++){
		vectorResult.elementos[i] = vector1.elementos[i] + vector2.elementos[i];
		}
	return vectorResult;
	}
