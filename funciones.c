#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Leer entero con validación
int leerEntero() {
    int num;
    char c;
    while (scanf("%d", &num) != 1) {
        printf("Entrada inválida. Ingresa un número entero: ");
        while ((c = getchar()) != '\n' && c != EOF);
    }
    while ((c = getchar()) != '\n' && c != EOF); 
    return num;
}

// Leer cadena segura
void leerCadena(char *cadena, int tam) {
    fgets(cadena, tam, stdin);
    cadena[strcspn(cadena, "\n")] = '\0';
}

// Registrar libro
void registrarLibro(struct Libro libros[], int *cantidad) {
    if (*cantidad >= 10) {
        printf("No se pueden registrar más libros (máximo 10).\n");
        return;
    }

    struct Libro nuevo;

    printf("Ingresa ID del libro: ");
    nuevo.id = leerEntero();

    // Validar ID único
    for (int i = 0; i < *cantidad; i++) {
        if (libros[i].id == nuevo.id) {
            printf("Error: El ID ya existe.\n");
            return;
        }
    }

    printf("Título: ");
    leerCadena(nuevo.titulo, 100);

    printf("Autor: ");
    leerCadena(nuevo.autor, 50);

    printf("Año de publicación: ");
    nuevo.anio = leerEntero();

    strcpy(nuevo.estado, "Disponible");

    libros[*cantidad] = nuevo;
    (*cantidad)++;

    printf("Libro registrado correctamente.\n");
}

// Mostrar libros
void mostrarLibros(struct Libro libros[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    printf("\n%-5s %-25s %-20s %-10s %-12s\n", "ID", "Título", "Autor", "Año", "Estado");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        printf("%-5d %-25s %-20s %-10d %-12s\n",
               libros[i].id,
               libros[i].titulo,
               libros[i].autor,
               libros[i].anio,
               libros[i].estado);
    }
}

// Buscar libro
void buscarLibro(struct Libro libros[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    int opcion;
    printf("\nBuscar por:\n1. ID\n2. Título\nOpción: ");
    opcion = leerEntero();

    if (opcion == 1) {
        int id;
        printf("Ingresa el ID: ");
        id = leerEntero();

        for (int i = 0; i < cantidad; i++) {
            if (libros[i].id == id) {
                printf("Libro encontrado:\n");
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor,
                       libros[i].anio, libros[i].estado);
                return;
            }
        }

        printf("No existe un libro con ese ID.\n");

    } else if (opcion == 2) {
        char titulo[100];
        printf("Ingresa el título: ");
        leerCadena(titulo, 100);

        for (int i = 0; i < cantidad; i++) {
            if (strcasecmp(libros[i].titulo, titulo) == 0) {
                printf("Libro encontrado:\n");
                printf("ID: %d\nTítulo: %s\nAutor: %s\nAño: %d\nEstado: %s\n",
                       libros[i].id, libros[i].titulo, libros[i].autor,
                       libros[i].anio, libros[i].estado);
                return;
            }
        }

        printf("No existe un libro con ese título.\n");
    } else {
        printf("Opción inválida.\n");
    }
}

// Actualizar estado
void actualizarEstado(struct Libro libros[], int cantidad) {
    if (cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    int id;
    printf("Ingresa ID del libro: ");
    id = leerEntero();

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            if (strcmp(libros[i].estado, "Disponible") == 0) {
                strcpy(libros[i].estado, "Prestado");
            } else {
                strcpy(libros[i].estado, "Disponible");
            }

            printf("Estado actualizado correctamente.\n");
            return;
        }
    }

    printf("No existe un libro con ese ID.\n");
}

// Eliminar libro
void eliminarLibro(struct Libro libros[], int *cantidad) {
    if (*cantidad == 0) {
        printf("No hay libros registrados.\n");
        return;
    }

    int id;
    printf("Ingresa ID del libro a eliminar: ");
    id = leerEntero();

    for (int i = 0; i < *cantidad; i++) {
        if (libros[i].id == id) {

            // Correr elementos
            for (int j = i; j < *cantidad - 1; j++) {
                libros[j] = libros[j + 1];
            }

            (*cantidad)--;
            printf("Libro eliminado.\n");
            return;
        }
    }

    printf("No existe un libro con ese ID.\n");
}
