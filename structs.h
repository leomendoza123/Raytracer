typedef struct{
int R;
int G;
int B;

} RGB;

typedef struct{
    double distancia;

} INTERSECTION;

typedef struct{
	double x;
	double y;
	double z;
} VECTOR;


typedef struct{
    int radio;
    RGB color;
    VECTOR punto;
} ESFERA;


typedef struct {

    VECTOR direccion;
    VECTOR origen;
} Ray;



