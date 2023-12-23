#ifndef FUNCIONES_H
#define FUNCIONES_H

// Estructura para los productos
typedef struct {
    char nombre[50];
    char clave[50];
} Facultad;

// Estructura para los usuarios
typedef struct {
    char nombre[50];
    char clave[50];
} Carrera;
// Estructura para las ventas
typedef struct {
    char matricula[50];
    char nombre[50];
    char apellido[20];
    char facultad;
    char carrera;
    float promedio;
    int materias_ap;
    int materias_rp;
} Estudiante;

#endif