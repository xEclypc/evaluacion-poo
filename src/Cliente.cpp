#include "Cliente.h"

Cliente::Cliente(int id, string n, string a)
{
    this->idCliente = id;
    this->nombre = n;
    this->apellido = a;
    //ctor
}

int Cliente::getIdCliente()
{
    return this->idCliente;
}

string Cliente::getNombre()
{
    return this->nombre;
}

string Cliente::getApellido()
{
    return this->apellido;
}

Cliente::~Cliente()
{
    //dtor
}
