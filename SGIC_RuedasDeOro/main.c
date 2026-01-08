#include <stdio.h>
#include "vehiculos.h"
#include "ventas.h"

int main() {
    int continuar = 1;
    int idCliente = 1;

    while (continuar) {
        char nombre[50];
        int edad;
        float presupuesto;
        int idVehiculo;

        printf("\n=== NUEVO CLIENTE ===\n");
        printf("Nombre: ");
        scanf("%s", nombre);

        printf("Edad: ");
        scanf("%d", &edad);

        printf("Presupuesto: ");
        scanf("%f", &presupuesto);

        registrarCliente(idCliente, nombre, edad, presupuesto);

        mostrarVehiculosDisponibles();

        do {
            printf("\nIngrese el ID del vehiculo que desea comprar: ");
            scanf("%d", &idVehiculo);

            if (!vehiculoValido(idVehiculo, presupuesto)) {
                printf(" Vehiculo no disponible o fuera de presupuesto.\n");
            }

        } while (!vehiculoValido(idVehiculo, presupuesto));

        marcarVehiculoVendido(idVehiculo);
        registrarVenta(idCliente, idVehiculo);

        printf("\n✅ Compra realizada con exito.\n");

        printf("\nDesea agregar otro cliente?\n1. Si\n0. No\nOpcion: ");
        scanf("%d", &continuar);

        idCliente++;
    }

    mostrarResumenVentas();
    return 0;
}

