#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;

class Cliente
{
    public:
        Cliente(int , string  , string);
        int getIdCliente();
        string getNombre();
        string getApellido();
        Cliente();
        virtual ~Cliente();

    protected:

    private:
         int idCliente;
        string nombre;
        string apellido;
};

#endif // CLIENTE_H
