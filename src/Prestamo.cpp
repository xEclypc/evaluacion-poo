#include "Prestamo.h"

Prestamo::Prestamo()
{
    this->numeroPrestamo = 0;
    this->cliente = new Cliente(0,"","");
    this->montoAprobado = 0;
    this->saldoPendiente = 0;
    this->contPagos = 0;
    this->fechaAprobacion = new Fecha(0,0,0);
    //ctor
}

Prestamo::Prestamo(int np, Cliente* _cliente, Fecha* _fechaAprobacion, float mp)
{
    this->numeroPrestamo = np;
    this->cliente = _cliente;
    this->fechaAprobacion = _fechaAprobacion;
    this->montoAprobado = mp;
    this->saldoPendiente = mp;
    this->contPagos = 0;

}

int Prestamo::getNumeroPrestamo()
{
    return this->numeroPrestamo;
}
void Prestamo::setNumeroPrestamo(int numeroPrestamo)
{
    this->numeroPrestamo = numeroPrestamo;
}
Cliente* Prestamo::getCliente()
{
    return this->cliente;
}
void Prestamo::setCliente(Cliente* cliente)
{
    this->cliente = cliente;
}
Fecha* Prestamo::getFechaAprobacion()
{
    return this->fechaAprobacion;
}
void Prestamo::setFechaAprobacion(Fecha* fechaAprobacion)
{
    this->fechaAprobacion = fechaAprobacion;
}
float Prestamo::getMontoAprobado()
{
    return this->montoAprobado;
}
void Prestamo::setMontoAprobado(float montoAprobado)
{
    this->montoAprobado = montoAprobado;
}
Pago** Prestamo::getLstPago()
{
    return this->lstPagos;
}
bool Prestamo::hacerPago(Pago* pago)
{
    bool  hacerPago = false;
    if(this->contPagos < DIM)
    {
        this->lstPagos[this->contPagos] = pago;
        contPagos++;
        this->saldoPendiente = this->saldoPendiente - pago->getMontoPago();
        hacerPago = true;
    }
    return hacerPago;

}
float Prestamo::getSaldoPendiente()
{
    return this->saldoPendiente;
}
int Prestamo::getContPagos()
{
    return this->contPagos;
}
Prestamo::~Prestamo()
{
    //dtor
}
