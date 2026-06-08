#include <stdio.h>
#include "funciones.h"

int main() {
    struct Libro libros[10];
    int cantidad = 0;
    int opcion;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("Elige una opcion: ");

        opcion = leerEntero();

        switch(opcion) {
            case 1: registrarLibro(libros, &cantidad); break;
            case 2: mostrarLibros(libros, cantidad); break;
            case 3: buscarLibro(libros, cantidad); break;
            case 4: actualizarEstado(libros, cantidad); break;
            case 5: eliminarLibro(libros, &cantidad); break;
            case 6: printf("Saliendo...\n"); break;
            default: printf("Opción inválida.\n");
        }

    } while(opcion != 6);

    return 0;
}
