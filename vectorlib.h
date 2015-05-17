
typedef struct VECTOR{
	long double element[3];
	}VECTOR;
long double getMagnitud(struct VECTOR vector);
struct VECTOR getNormalizedVector(struct VECTOR vector);
long double vectorXvector(struct VECTOR vector1, struct VECTOR vector2);
struct VECTOR vectorPlusVector(struct VECTOR vector1, struct VECTOR vector2);
struct VECTOR vectorPlusInteger(struct VECTOR vector, int escalar);
struct VECTOR vectorPlusLongDouble(struct VECTOR vector, long double escalar);
