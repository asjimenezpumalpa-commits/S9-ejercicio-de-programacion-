#ifndef FUNCIONES_H
#define FUNCIONES_H

struct Libro {
    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[20];
};

// --- Prototipos ---
int leerEntero();
void leerCadena(char *cadena, int tam);

void registrarLibro(struct Libro libros[], int *cantidad);
void mostrarLibros(struct Libro libros[], int cantidad);
void buscarLibro(struct Libro libros[], int cantidad);
void actualizarEstado(struct Libro libros[], int cantidad);
void eliminarLibro(struct Libro libros[], int *cantidad);

#endif
