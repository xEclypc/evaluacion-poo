#include <iostream>
#include "Cliente.h"
#include "Fecha.h"
#include "Prestamo.h"
#include "Pago.h"
#include<stdlib.h>
#define DIM 5
using namespace std;

int menu()
{

    int opc;
    cout << " --MENU DE OPCIONES-- \n";
    cout << "1. AGREGAR CLIENTES A LA LISTA \n";
    cout << "2. AGREGAR PRESTAMO A LA LISTA  \n";
    cout << "3. HACER PAGOS DE PRESTAMOS \n";
    cout << "4. MOSTRAR LISTA DE CLIENTES \n";
    cout << "5. MOSTRAR LISTA DE PRESTAMOS \n";
    cout << "6. MOSTRAR DETALLES DE PRESTAMO \n";
    cout << "7. SALIR \n";
    cout << "Ingrese una opcion: ";
    cin >> opc;
    return opc;
}
Cliente* agregarCliente()
{
    int idCliente;
    string nombre, apellido;
    Cliente* cliente;
    cout << "Ingrese el id del cliente: ";
    cin >> idCliente;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingresar el apellido del cliente: ";
    cin >> apellido;
    cliente = new Cliente(idCliente, nombre, apellido);
    return cliente;

}
Cliente* buscarCliente(Cliente* lista[], int contadorCliente,int db)
{
    bool encontrar = false;
    int contadorBuscar = 0;
    Cliente* cliente = NULL;
    while(contadorBuscar < contadorCliente && !encontrar)
    {
        if(lista[contadorBuscar]->getIdCliente() == db)
        {
            encontrar = true;
            cliente = lista[contadorBuscar];
        }else{
            contadorBuscar = contadorBuscar + 1;
        }
    }
    return cliente;
}
Prestamo* agregarPrestamo(Cliente* cli)
{

    int d, m, a, np;
    float mp;
    Fecha* fechaAprobacion;
    Prestamo* prestamo;

    cout << "Ingrese el numero de prestamo: ";
    cin >> np;
    cout << "Ingrese la fecha de aprobacion: \n";
    cout << "DIA: \n";
    cin >> d;
    cout << "MES: \n";
    cin >> m;
    cout << "AÑO: \n";
    cin >> a;
    fechaAprobacion = new Fecha(d, m, a);
    cout << "Digite el monto aprobado: ";
    cin >> mp;
    prestamo = new Prestamo(np, cli, fechaAprobacion, mp);
    return prestamo;


}
Prestamo* buscarPrestamo(Prestamo* lista[], int contadorPrestamo,int db)
{
    bool encontrar = false;
    int contadorBuscar = 0;
    Prestamo* prestamo = NULL;
    while(contadorBuscar < contadorPrestamo && !encontrar)
    {
        if(lista[contadorBuscar]->getNumeroPrestamo() == db)
        {
            encontrar = true;
            prestamo = lista[contadorBuscar];
        }else{
            contadorBuscar = contadorBuscar + 1;
        }
    }
    return prestamo;
}
void registrarPago(Prestamo *prestamo)
{
    int d, m, a;
    Fecha* fechaPago;
    float montoPago;
    Pago* pago;
    cout << "Ingrese la fecha de pago: \n";
    cout << "DIA: \n";
    cin >> d;
    cout << "MES: \n";
    cin >> m;
    cout << "AÑO: \n";
    cin >> a;
    cout << "Ingrese el monto a pagar: ";
    cin >> montoPago;
    fechaPago = new Fecha(d, m, a);
    pago = new Pago(fechaPago, montoPago);
    prestamo->hacerPago(pago);
}
void verDetalles(Prestamo *prestamo)
{
    cout << "NUMERO: ";
    cout << prestamo->getNumeroPrestamo() << "\n";
    cout << "CLIENTE: ";
    cout << prestamo->getCliente()->getNombre() << " " <<  prestamo->getCliente()->getApellido() << "\n";
    cout << "FECHA APROBACION: ";
    prestamo->getFechaAprobacion()->mostrarFecha();
    cout << "MONTO APROBADO: " << prestamo->getMontoAprobado();
    cout << "\nSALDO PENDIENTE: ";
    cout << prestamo->getSaldoPendiente();
    if(prestamo->getContPagos() == 0)
    {
        cout << "\nPagos no registrados";
    }else{
        Pago** lista = prestamo->getLstPago();
        for (int i = 0;i < prestamo->getContPagos();i++)

        {
            cout << "\nFECHA PAGO: ";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "MONTO: ";
            cout << lista[i]->getMontoPago() << endl;
        }

    }


}
void mostrarListaCLIENTES(Cliente* listaClientes[DIM], int contadorClientes)
{
    if(contadorClientes == 0)
    {
        cout << "Carpeta vacia..";
    }else{
        cout << "ID \t NOMBRE \t APELLIDO \n";
        for(int i = 0; i < contadorClientes; i = i + 1)
        {
            cout << listaClientes[i]->getIdCliente() << " \t " << endl;
            cout << listaClientes[i]->getNombre() << " \t " << endl;
            cout << listaClientes[i]->getApellido() << " \n " << endl;

        }
    }
}
void mostrarListaPRESTAMO(Prestamo* listaPrestamos[DIM], int contadorPrestamos)
{
    if(contadorPrestamos == 0)
    {
        cout << "Carpeta vacia..";
    }else{
        cout << "ID \t NOMBRE \t APELLIDO \n";
        for(int i = 0; i < contadorPrestamos; i = i + 1)
        {
            cout << listaPrestamos[i]->getNumeroPrestamo() << " \t " << endl;
            cout << listaPrestamos[i]->getCliente()->getNombre() << " \t " << endl;
            cout << listaPrestamos[i]->getCliente()->getApellido() << " \t " << endl;
            listaPrestamos[i]->getFechaAprobacion( )->mostrarFecha();
            cout << " \t ";
            cout << listaPrestamos[i]->getMontoAprobado() << " \n ";


        }
    }
}
int main()
{
    setlocale(LC_ALL, "spanish");
    Cliente* listaClientes[DIM];
    Prestamo* listaPrestamos[DIM];
    Cliente* cliente = NULL;
    Prestamo* prestamo = NULL;
    int contClientes= 0,contPrestamos= 0, idClientes = 0, idPrestamos = 0;
    int opcion = 0;
    do
    {
        system("cls");
        opcion = menu();
        switch(opcion)
        {
        case 1:

            if(contClientes < DIM)
            {
                listaClientes[contClientes] = agregarCliente();
                contClientes = contClientes + 1;
                cout << "Los datos del usuario se han registrado con exito!";
            }else{
                cout << "La lista de clientes esta llena..";
            }

            break;
        case 2:

            if(contPrestamos < DIM)
            {
                cout << "Digite id del cliente: ";
                cin >> idClientes;
                cliente = buscarCliente(listaClientes, contClientes, idClientes);
                if(cliente)
                {
                    listaPrestamos[contPrestamos] = agregarPrestamo(cliente);
                    contPrestamos = contPrestamos + 1;
                    cout << "Los datos del prestamo se han registrado con exito!";
                }else{
                    cout << "Cliente no identificado";
                }
            }

            break;
        case 3:

            cout << "Digite el numero de prestamo: ";
            cin >> idPrestamos;
            prestamo = buscarPrestamo(listaPrestamos, contPrestamos, idPrestamos);
            if(prestamo)
            {
                registrarPago(prestamo);
                cout << "El pago se registro con exito! " <<endl;
            }else{
                cout << "El pago no se puede realizar, el registro no existe.." <<endl;
            }

            break;
        case 4:
            if(contClientes == 0)
                {
                    cout << "La lista esta vacia..";
                }else{
                    for(int i = 0; i < contClientes; i++)
                    {
                        cout << "ID: ";
                        cout << listaClientes[i]->getIdCliente() << "\n";
                        cout << "NOMBRE: ";
                        cout << listaClientes[i]->getNombre() << "\n";
                        cout << "APELLIDO: ";
                        cout << listaClientes[i]->getApellido();
                    }
                }
            break;
        case 5:

             if(contPrestamos == 0)
                {
                    cout << "La lista esta vacia..";
                }else{
                    for(int i = 0; i < contPrestamos; i++)
                    {
                        cout << "NO: ";
                        cout << listaPrestamos[i]->getNumeroPrestamo()<< "\n";
                        cout << "NOMBRE COMPLETO: ";
                        cout << listaPrestamos[i]->getCliente()->getNombre()<< " ";
                        cout << listaPrestamos[i]->getCliente()->getApellido()<< "\n";
                        cout << "FECHA: ";
                        listaPrestamos[i]->getFechaAprobacion()->mostrarFecha();
                        cout << "MONTO: ";
                        cout << listaPrestamos[i]->getMontoAprobado()<< "\n";
                        cout << "SALDO: ";
                        cout << listaPrestamos[i]->getSaldoPendiente() << "\n";
                    }
                }

            break;
        case 6:

            cout << "Digite el numero del prestamo: ";
            cin >> idPrestamos;
            prestamo = buscarPrestamo(listaPrestamos, contPrestamos, idPrestamos);
            if(prestamo)
            {
                verDetalles(prestamo);
            }else{
                cout << "Carpeta vacia..";
            }

            break;
        case 7:

            cout << "Saliendo del programa..\n";
            system("pause >> NULL");
            for(int i = 0; i < 10; i++)
            {
                cout << "[.]";
                system("cls");
                cout << "[..]";
                system("cls");
                cout << "[...]";
                system("cls");
            }
            cout << "Cerrando archivos..";
            system("cls");
            cout << "Apagando equipo..";
            system("cls");
            break;

        default:

            cout << "Numero invalido.. Porfavor vuelva intentarlo. ";

            break;

        }
        system("pause >> NULL");
    }while(opcion != 7);
    return 0;
}
