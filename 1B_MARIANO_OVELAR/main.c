#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include "propietario_funciones.h"
#include "autos_funciones.h"

#define TAM_ESTACIONAMIENTO 20
#define TAM_PROPIETARIO 100
#define TAM_MARCA 4

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int main()
{
    Epropietario listaPropietarios[TAM_PROPIETARIO];
    Eauto listaAutos[TAM_ESTACIONAMIENTO];

    char seguir='s';
    int opcion;
    int lugar;
    int auxInt;
    int horas;
    int flag;
    char patente[20];
    //float recaudado=0;
    float *acumuladorPorMarca=(float*) malloc(sizeof(float)*TAM_MARCA);
    int i;

    for(i=0; i<TAM_MARCA; i++)
    {
        *(acumuladorPorMarca+i)=0;
    }

    iniEstadoPersona(listaPropietarios,TAM_PROPIETARIO);

    inicializarUsuariosHardCode(listaPropietarios);

    iniEstadoAuto(listaAutos,TAM_ESTACIONAMIENTO);

    inicializarAutosHardCode(listaAutos);



    do
    {
        printf("1- Alta de propietario\n");
        printf("2- Modificar propietario\n");
        printf("3- Baja de propietario\n");
        printf("4- Ingreso del automovil\n");
        printf("5- Egreso del automovil\n");
        printf("6- Recaudacion total del estacionamiento\n");
        printf("7- Recaudacion total por marca\n");
        printf("8- listar propietarios con sus autos\n");
        printf("9- listar los autos audi propietarios\n");
        printf("10- Listado de autos estacionados con sus propietario (ordenado por patente)\n");
        printf("20- Salir\n");

        opcion=ingresoInt("\nINGRESE OPCION: ");

        switch(opcion)
        {
        case 1:
        {
            system("cls");
            mostrarListaPropietario(listaPropietarios,TAM_PROPIETARIO);
            printf("OPCION %d:\n\n",opcion);

            lugar=obtenerEspacioLibre(listaPropietarios,TAM_PROPIETARIO);
            cargaDeDatosPersona(listaPropietarios,lugar,TAM_PROPIETARIO);

            break;
        }
        case 2:
        {
            system("cls");
            mostrarListaPropietario(listaPropietarios,TAM_PROPIETARIO);
            printf("OPCION %d:\n\n",opcion);

            auxInt=ingresoInt("INGRESE ID:");
            lugar=buscarPorIdPersona(listaPropietarios,auxInt,TAM_PROPIETARIO);
            modificarPropietario(listaPropietarios,lugar);

            break;
        }
        case 3:
        {
            system("cls");
            mostrarListaPropietarioConSusAutos(listaPropietarios,TAM_PROPIETARIO,listaAutos,TAM_ESTACIONAMIENTO);
            printf("OPCION %d:\n\n",opcion);

            auxInt=ingresoInt("INGRESE ID:");
            lugar=buscarPorIdPersona(listaPropietarios,auxInt,TAM_PROPIETARIO);
            darBajaPersona(listaPropietarios,lugar);

            darBajaTodosLosAutosDelPropietario(listaAutos,listaPropietarios[lugar],TAM_ESTACIONAMIENTO,acumuladorPorMarca);

            break;
        }
        case 4:
        {
            system("cls");
            mostrarListaPropietario(listaPropietarios,TAM_PROPIETARIO);
            printf("OPCION %d:\n\n",opcion);

            lugar=obtenerEspacioLibreEstacionamiento(listaAutos,TAM_ESTACIONAMIENTO);
            cargaDeDatosAuto(listaAutos,listaPropietarios,lugar,TAM_ESTACIONAMIENTO,TAM_PROPIETARIO);

            break;
        }
        case 5:
        {
            system("cls");
            mostrarListaAutos(listaAutos,TAM_ESTACIONAMIENTO);
            printf("OPCION %d:\n\n",opcion);

            igresoCadenaChar("INGRESE PATENTE: ",patente);

            lugar=buscarPatente(listaAutos,patente,TAM_ESTACIONAMIENTO);

            flag=darBajaAuto(listaAutos,lugar);
            if(flag==0)
            {
                horas=devolverHorasEstadia();

                acumuladorPorMarca[(listaAutos[lugar].marca)-1]+=darTike(listaAutos,TAM_ESTACIONAMIENTO,lugar,listaPropietarios,horas);
            }

            break;
        }
        case 6:
        {
            system("cls");
            printf("OPCION %d:\n\n",opcion);

            /* recaudado=*/totalRecaudado(acumuladorPorMarca,TAM_MARCA);


            break;
        }
        case 7:
        {
            system("cls");
            printf("OPCION %d:\n\n",opcion);

            recaudacionPorMarca(acumuladorPorMarca,TAM_MARCA);

            break;
        }

        case 8:
        {
            system("cls");
            printf("OPCION %d:\n\n",opcion);

            mostrarListaPropietarioConSusAutos(listaPropietarios,TAM_PROPIETARIO,listaAutos,TAM_ESTACIONAMIENTO);

            break;
        }
        case 9:
        {
            system("cls");
            printf("OPCION %d:\n\n",opcion);

            listaAutosDeUnaMarca(listaAutos,TAM_ESTACIONAMIENTO,listaPropietarios,TAM_PROPIETARIO,AUDI);

            break;
        }
        case 10:
        {
            system("cls");
            printf("OPCION %d:\n\n",opcion);

            ordenarPatentes(listaAutos,TAM_ESTACIONAMIENTO);

            mostrarListaAutosConSusPropietrios(listaPropietarios,TAM_PROPIETARIO,listaAutos,TAM_ESTACIONAMIENTO);



            break;
        }
        case 20:
        {
            seguir = 'n';
            break;
        }
        }
        system("pause");
        system("cls");
    }
    while(seguir=='s');

    return 0;

}
