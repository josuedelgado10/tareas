#include <stdio.h>
#include "vehiculos.h"

void mostrarVehiculosDisponibles(void) {
    FILE *f = fopen("datos/vehiculos.txt", "r");
    Vehiculo v;

    if (f == NULL) {
        printf("Error al abrir vehiculos.txt\n");
        return;
    }

    printf("\n=== VEHICULOS DISPONIBLES ===\n");

    while (fscanf(f, "%d %s %s %s %d %f %d %d",
                  &v.id, v.tipo, v.marca, v.modelo,
                  &v.anio, &v.precio, &v.usado, &v.disponible) != EOF) {

        if (v.disponible == 1) {
            printf("ID:%d | %s %s %d | $%.2f\n",
                   v.id, v.marca, v.modelo, v.anio, v.precio);
        }
    }

    fclose(f);
}

int vehiculoValido(int idVehiculo, float presupuesto) {
    FILE *f = fopen("datos/vehiculos.txt", "r");
    Vehiculo v;

    if (f == NULL) return 0;

    while (fscanf(f, "%d %s %s %s %d %f %d %d",
                  &v.id, v.tipo, v.marca, v.modelo,
                  &v.anio, &v.precio, &v.usado, &v.disponible) != EOF) {

        if (v.id == idVehiculo &&
            v.disponible == 1 &&
            v.precio <= presupuesto) {
            fclose(f);
            return 1;
        }
    }

    fclose(f);
    return 0;
}

void marcarVehiculoVendido(int idVehiculo) {
    FILE *f = fopen("datos/vehiculos.txt", "r");
    FILE *temp = fopen("datos/temp.txt", "w");
    Vehiculo v;

    if (f == NULL || temp == NULL) return;

    while (fscanf(f, "%d %s %s %s %d %f %d %d",
                  &v.id, v.tipo, v.marca, v.modelo,
                  &v.anio, &v.precio, &v.usado, &v.disponible) != EOF) {

        if (v.id == idVehiculo) {
            v.disponible = 0;
        }

        fprintf(temp, "%d %s %s %s %d %.2f %d %d\n",
                v.id, v.tipo, v.marca, v.modelo,
                v.anio, v.precio, v.usado, v.disponible);
    }

    fclose(f);
    fclose(temp);

    remove("datos/vehiculos.txt");
    rename("datos/temp.txt", "datos/vehiculos.txt");
}
