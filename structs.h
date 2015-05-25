
typedef struct{
int R;
int G;
int B;

} RGB;

typedef struct{
    double distancia;
    RGB color;

} INTERSECTION;

typedef struct{
    int radio;
    RGB color;
    VECTOR punto;
} ESFERA;


typedef struct{
    VECTOR origen;
} LUZ;


typedef struct {

    VECTOR direccion;
    VECTOR origen;
} Ray;



