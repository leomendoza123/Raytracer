
typedef struct{
double R;
double G;
double B;

} RGB;


typedef struct{
    int radio;
    RGB color;
    VECTOR punto;
} ESFERA;

typedef struct{
    double distancia;
    ESFERA esfera;
    VECTOR puntoInterseccion;

} INTERSECTION;

typedef struct{
    VECTOR origen;
} LUZ;


typedef struct {

    VECTOR direccion;
    VECTOR origen;
} Ray;



