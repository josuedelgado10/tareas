#ifndef VENTAS_H
#define VENTAS_H

void registrarCliente(int id, char nombre[], int edad, float presupuesto);
void registrarVenta(int idCliente, int idVehiculo);
void mostrarResumenVentas(void);

#endif

