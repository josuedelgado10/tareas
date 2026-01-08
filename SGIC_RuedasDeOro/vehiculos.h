#ifndef VEHICULOS_H
#define VEHICULOS_H

typedef struct {
    int id;
    char tipo[20];
    char marca[20];
    char modelo[30];
    int anio;
    float precio;
    int usado;
    int disponible;
} Vehiculo;

void mostrarVehiculosDisponibles(void);
int vehiculoValido(int idVehiculo, float presupuesto);
void marcarVehiculoVendido(int idVehiculo);

#endif
