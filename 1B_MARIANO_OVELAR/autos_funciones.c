#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "propietario_funciones.h"
#include "autos_funciones.h"
#include "funciones.h"
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4


int iniEstadoAuto(Eauto lista[],int tam)
{
    int i;

    int flag=-1;

    if(lista!=NULL&&tam>0)
    {
        flag=0;
        for(i=0; i<tam; i++)
        {
            lista[i].estado=0;
        }
    }
    return flag;
}

void inicializarAutosHardCode(Eauto lista[])
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};

    int i;

    for(i=0; i<10; i++)
    {
        lista[i].id=id[i];
        strcpy(lista[i].patente, patente[i]);
        lista[i].marca=marca[i];
        lista[i].idPropietario=propietario[i];
        lista[i].estado = 1;
    }

}
int obtenerEspacioLibreEstacionamiento(Eauto lista[],int tam)
{
    int i;
    int aux=-1;

    if(lista!=NULL&&tam>0)
    {
        aux=-2;
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==0)
            {
                aux=i;
                break;
            }
        }
    }
    return aux;
}

int cargaDeDatosAuto(Eauto lista[],Epropietario listaPro[],int lugar,int tam,int tamPro)
{
    Eauto nuevo;
    int esValido;
    int flag=-1;

    if(lista!=NULL&&tam>0)
    {
        if(lugar==-1)
        {
            flag=1;
            printf("\n\nNO SE PUDO ENCONTRAR ESPACIO EN EL SISTEMA...\n\n");
        }
        else
        {
            flag=0;
            printf("INGRESE DATOS:\n\n");

            do
            {
                igresoCadenaChar("INGRESE PATENTE: ",nuevo.patente);
                esValido=validarPatente(nuevo.patente,lista,tam);
                if(esValido)
                {
                    printf("SE A PRODUCIDO UN ERROR!!!!!\n\n");
                }
            }
            while(esValido);

            do
            {
                esValido=-1;
                printf("\n1- ALPHA ROMEO");
                printf("2- FERRARI");
                printf("3- AUDI");
                printf("4- OTROS\n");

                nuevo.marca=ingresoInt("INGRESE MARCA: ");

                if(nuevo.marca>=1&&nuevo.marca<=4)
                {
                    esValido=0;
                }
                else
                {
                    printf("OPCION NO VALIDA!!!!!\n");
                    esValido=-1;
                }
            }
            while(esValido);

            do
            {
                nuevo.idPropietario=ingresoInt("INGRESE ID PROPIETARIO: ");
                if(!(nuevo.id<0))
                {
                    esValido=validarId(nuevo.idPropietario,listaPro,tamPro);

                    if(esValido==-2)
                    {
                        esValido=0;
                    }
                    else
                    {
                        esValido=-1;
                        printf("ID NO VALIDO\n\n");
                    }
                }
            }
            while(esValido);

            nuevo.id=lugar+1;

            nuevo.estado=1;

            lista[lugar]=nuevo;
        }
    }
    return flag;
}

int buscarPatente(Eauto lista[],char dato[],int tam)
{
    int i;
    int aux=-1;

    if(lista!=NULL&&dato!=0&&tam>0)
    {
        aux=-2;
        for(i=0; i<tam; i++)
        {
            if(strcasecmp(dato,lista[i].patente)==0)
            {
                aux=i;
                break;
            }
        }
    }
    return aux;
}

int validarPatente(char dato[],Eauto lista[],int tam)
{
    int lugar;
    int flag=-1;


    if(dato!=NULL&&lista!=NULL&&tam>0)
    {
        lugar=buscarPatente(lista,dato,tam);
        if(lugar==-1)
        {
            printf("ERROR EN LA BUSQUEDA!!!!\n\n");
            flag=-1;
        }
        else if(lugar==-2)
        {
            flag=0;
        }
        else
        {
            //printf("\nYA EXISTE ESTA PATENTE!!!!\n");
            flag=-2;
        }
    }
    return flag;
}
float devolverPrecio(Eauto listaAuto[],int lugar)
{
    float precio=-1;

    if(listaAuto!=NULL&&lugar>=0)
    {
        if(listaAuto[lugar].marca==ALPHA_ROMEO)
        {
            precio=150;
        }
        else if(listaAuto[lugar].marca==FERRARI)
        {
            precio=175;
        }
        else if(listaAuto[lugar].marca==AUDI)
        {
            precio=200;
        }
        else if(listaAuto[lugar].marca==OTROS)
        {
            precio=250;
        }
    }

    return precio;
}

int darBajaAuto(Eauto lista[],int ubicacion)
{
    char borrar;
    int flag=-1;
    char marca[20];

    if(lista!=NULL&&ubicacion>=0)
    {
        flag=0;
        devolverMarca(lista[ubicacion].marca,marca);
        printf("\n\nQUIERE DAR DE BAJA AL AUTO?\n\nMARCA: %s\n\nPATENTE: %s\n\nLUGAR: %d\n\n",marca,lista[ubicacion].patente,lista[ubicacion].id);
        printf("\nINGRESE OPCION [S/N]: ");
        borrar=getche();
        if(borrar=='s'||borrar=='S')
        {
            lista[ubicacion].estado=0;
            printf("\n\nFUE DADO DE BAJA!!!!!\n\n");
        }
        else
        {
            flag=-2;
            printf("\n\nORDEN CANSELADA!!!!!\n\n");
        }
    }
    if(ubicacion==-1)
    {
        printf("\nNO SE A ENCUENTRA EN LA LISTA!!!!!\n\n");
    }
    return flag;
}

int mostrarListaAutos(Eauto lista[],int tam)
{
    int i;
    int flag=-1;
    char marca[20];

    if(lista!=NULL&&tam>0)
    {
        flag=1;

        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==1)
            {
                devolverMarca(lista[i].marca,marca);
                printf("\nPATENTE: %s -- LUGAR: %d -- MARCA: %s\n",lista[i].patente,lista[i].id,marca);
                printf("----------------------------------------------\n");
                flag=0;
            }
        }
        if(flag)
        {
            printf("LA LISTA ESTA VACIA!!!!\n\n");
        }
    }
    return flag;
}
void devolverMarca(int marca,char dato[])
{

    if(marca>0)
    {
        if(marca==ALPHA_ROMEO)
        {
            strcpy(dato,"ALPHA ROMEO");
        }
        else if(marca==FERRARI)
        {
            strcpy(dato,"FERRARI");
        }
        else if(marca==AUDI)
        {
            strcpy(dato,"AUDI");
        }
        else if(marca==OTROS)
        {
            strcpy(dato,"OTROS");
        }
    }
}
void mostrarAutoConPropietario(Eauto listaAuto[],Epropietario listaPropietario[],int lugarAuto,int tamPropietarios)
{
    int i;
    char marca[20];

    for(i=0; i<tamPropietarios; i++)
    {
        if(listaAuto[lugarAuto].idPropietario==listaPropietario[i].id)
        {
            break;
        }
    }

    devolverMarca(listaAuto[lugarAuto].marca,marca);

    printf("TIKE:\n\n");
    printf("PROPIETARIO: %s\n\nMARCA: %s\n\nPATENTE: %s\n\n",listaPropietario[i].nombre,marca,listaAuto[lugarAuto].patente);
}

int seleccionarMarcar()
{
    int opcion;

    do
    {
        printf("1_ ALPHA ROMEO\n");
        printf("2_ FERRARI\n");
        printf("3_ AUDI\n");
        printf("4_ OTROS\n");
        opcion=ingresoInt("\nINGRESE LA MARCA: ");

        if(!(opcion>0&&opcion<5))
        {
            printf("ERROR: SOLO PUEDE ELEGIR LAS MARCA DEL MENU!!!!\n\n");
            opcion=-1;
        }
    }
    while(opcion==-1);

    return opcion;
}

void recaudacionPorMarca(float *recaudaciones,int tam)
{
    int i;
    char marca[20];

    printf("SERECAUDO: \n\n");
    for(i=0; i<tam; i++)
    {
        devolverMarca(i+1,marca);
        printf("%s $%.2f\n\n",marca,*(recaudaciones+i));
    }
}

void listaAutosDeUnaMarca(Eauto listaAut[],int tamAut,Epropietario listPro[],int tamPro,int numMarca)
{
    int i,j;
    char marca[20];

    devolverMarca(numMarca,marca);

    printf("TODO LOS PROPIETARIOS DE AUTOS %s\n\n",marca);

    for(i=0; i<tamAut; i++)
    {
        if((numMarca==listaAut[i].marca)&&(listaAut[i].estado==1))
        {
            for(j=0; j<tamPro; j++)
            {
                if((listaAut[i].idPropietario==listPro[j].id)&&(listPro[j].estado==1))
                {
                    printf("PATENTE: %s -- LUGAR: %d\n\n",listaAut[i].patente,listaAut[i].id);
                    printf("ID: %d -- NOMBRE: %s -- APELLIDO: %s\n\n",listPro[j].id,listPro[j].nombre,listPro[j].apellido);
                    printf("-----------------------------------------------------------\n");
                }
            }
        }
    }

}

int mostrarListaAutosConSusPropietrios(Epropietario listaPropietarios[],int tamPro,Eauto listaAuto[],int tamAut)
{
    int i,j;
    int flag=-1;
    char marca[20];
    if(listaPropietarios!=NULL&&listaAuto!=NULL&&tamAut>0&&tamPro>0)
    {
        flag=1;
        for(i=0; i<tamPro; i++)
        {
            if(listaAuto[i].estado==1)
            {
                devolverMarca(listaAuto[i].marca,marca);
                printf("AUTOS:\n\nPATENTE: %s -- LUGAR: %d -- MARCA: %s\n",listaAuto[i].patente,listaAuto[i].id,marca);

                for(j=0; j<tamAut; j++)
                {
                    if((listaPropietarios[j].estado==1)&&(listaAuto[i].idPropietario==listaPropietarios[j].id))
                    {
                        printf("PROPIETARIO:\n\nID: %d -- NOMBRE: %s -- APELLIDO: %s \n\n",listaPropietarios[j].id,listaPropietarios[j].nombre,listaPropietarios[j].apellido);
                    }
                }
                printf("-----------------------------------------------------------\n");
                flag=0;
            }
        }
    }
    return flag;
}

void ordenarPatentes(Eauto listaAut[],int tam)
{
    int i,j;
    Eauto aux;
    for(i=0; i<=tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(strcmp(listaAut[i].patente,listaAut[j].patente)<0)
            {
                aux=listaAut[i];
                listaAut[i]=listaAut[j];
                listaAut[j]=aux;
            }
        }
    }
}


