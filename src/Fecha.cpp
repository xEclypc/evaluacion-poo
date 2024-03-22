#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int d, int m, int a)
{
    this->dia = d;
    this->mes = m;
    this->anio = a;
    //ctor
}
void Fecha::mostrarFecha()
{
    cout << dia << " - " << mes << " - " << anio << endl;
}

Fecha::~Fecha()
{
    //dtor
}
