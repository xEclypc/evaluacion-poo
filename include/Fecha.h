#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha(int , int , int);
        void mostrarFecha();
        Fecha();
        virtual ~Fecha();

    protected:

    private:
        int dia;
        int mes;
        int anio;

};

#endif // FECHA_H
