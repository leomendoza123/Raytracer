
typedef struct{
double R;
double G;
double B;

} RGB;


typedef struct{
    int radio;
    RGB color;
    VECTOR punto;
    double KD;
} ESFERA;

typedef struct{
    double distancia;
    ESFERA esfera;
    VECTOR puntoInterseccion;

} INTERSECTION;

typedef struct{
    VECTOR origen;
    double Ip;
} LUZ;


typedef struct {

    VECTOR direccion;
    VECTOR origen;
} Ray;



