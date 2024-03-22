#ifndef PRESTAMO_H
#define PRESTAMO_H
#define DIM 5
#include "Fecha.h"
#include "Pago.h"
#include "Cliente.h"


class Prestamo
{
    public:
        Prestamo(int, Cliente*, Fecha*, float);
        int getNumeroPrestamo();
        void setNumeroPrestamo(int);
        Cliente* getCliente();
        void setCliente(Cliente*);
        Fecha* getFechaAprobacion();
        void setFechaAprobacion(Fecha*);
        float getMontoAprobado();
        void setMontoAprobado(float);
        Pago** getLstPago();
        bool hacerPago(Pago*);
        float getSaldoPendiente();
        int getContPagos();
        Prestamo();
        virtual ~Prestamo();

    protected:

    private:
        int numeroPrestamo;
        Fecha* fechaAprobacion;
        Cliente* cliente;
        float montoAprobado;
        Pago* lstPagos[DIM];
        float saldoPendiente;
        int contPagos;
};

#endif // PRESTAMO_H
