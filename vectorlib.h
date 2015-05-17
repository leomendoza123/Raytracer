
typedef struct VECTOR{
	long double elementos[3];
	}VECTOR;

struct VECTOR vectorMasVector(struct VECTOR vector1, struct VECTOR vector2);
struct VECTOR vectorMasEntero(struct VECTOR vector, int escalar);
struct VECTOR vectorMasLongDouble(struct VECTOR vector, long double escalar);
