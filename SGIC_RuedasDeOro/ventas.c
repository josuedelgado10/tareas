#include <stdio.h>
#include "ventas.h"

void registrarCliente(int id, char nombre[], int edad, float presupuesto) {
    FILE *f = fopen("datos/clientes.txt", "a");
    if (f == NULL) return;

    fprintf(f, "%d %s %d %.2f\n", id, nombre, edad, presupuesto);
    fclose(f);
}

void registrarVenta(int idCliente, int idVehiculo) {
    FILE *f = fopen("datos/ventas.txt", "a");
    if (f == NULL) return;

    fprintf(f, "Cliente:%d Vehiculo:%d\n", idCliente, idVehiculo);
    fclose(f);
}

void mostrarResumenVentas(void) {
    FILE *f = fopen("datos/ventas.txt", "r");
    char linea[100];

    printf("\n===== RESUMEN DE VENTAS =====\n");

    if (f == NULL) {
        printf("No hay ventas registradas.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), f)) {
        printf("%s", linea);
    }

    fclose(f);
}



