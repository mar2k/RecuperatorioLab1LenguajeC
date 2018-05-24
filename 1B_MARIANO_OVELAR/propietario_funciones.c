#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "propietario_funciones.h"
#include "autos_funciones.h"
#include "funciones.h"


int iniEstadoPersona(Epropietario lista[],int tam)
{
    int i;

    int flag=-1;

    if(lista!=NULL&&tam>0)
    {
        flag=0;
        for(i=0; i<tam; i++)
        {
            lista[i].estado=0;
            //lista[i].id=0;
        }
    }
    return flag;
}

int obtenerEspacioLibre(Epropietario lista[],int tam)
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


int cargaDeDatosPersona(Epropietario lista[],int lugar,int tam)
{
    Epropietario nuevo;
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
                igresoCadenaChar("INGRESE NOMBRE: ",nuevo.nombre);
                esValido=validarSiSonLetra(nuevo.nombre);
            }
            while(esValido);

            do
            {
                igresoCadenaChar("INGRESE APELLIDO: ",nuevo.apellido);
                esValido=validarSiSonLetra(nuevo.apellido);
            }
            while(esValido);

            do
            {
                esValido=-1;
                nuevo.id=ingresoInt("INGRESE ID: ");
                if(!(nuevo.id<0))
                {
                    esValido=validarId(nuevo.id,lista,tam);
                    if(esValido)
                    {
                        printf("SE A PRODUCIDO UN ERROR!!!!!\n\n");
                    }
                }
            }
            while(esValido);

            do
            {
                igresoCadenaChar("INGRESE NUMERO DE TARJETA DE CREDITO: ",nuevo.numDeTarjeta);
                esValido=validarTarjeta(nuevo.numDeTarjeta,lista,tam);
                if(esValido)
                {
                    printf("SE A PRODUCIDO UN ERROR!!!!!\n\n");
                }
            }
            while(esValido);

            do
            {
                igresoCadenaChar("INGRESE DIRECCION: ",nuevo.direccion);
                esValido=validarSiSonLetra(nuevo.direccion);
            }
            while(esValido);

            nuevo.estado=1;

            lista[lugar]=nuevo;
        }
    }
    return flag;
}

int validarId(int id,Epropietario lista[],int tam)
{
    int lugar;
    int flag=-1;

    if(id!=0&&lista!=NULL&&tam>0)
    {
        lugar=buscarPorIdPersona(lista,id,tam);
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
            //printf("\nYA EXISTE ESTE ID EN LA LISTA!!!!\n");
            flag=-2;
        }
    }
    return flag;
}

int buscarPorIdPersona(Epropietario lista[],int id,int tam)
{
    int i;
    int aux=-1;

    if(lista!=NULL&&id!=0&&tam>0)
    {
        aux=-2;
        for(i=0; i<tam; i++)
        {
            if(id==lista[i].id)
            {
                aux=i;
                break;
            }
        }
    }
    return aux;
}

int validarTarjeta(char num[],Epropietario lista[],int tam)
{
    int lugar;
    int flag=-1;


    if(num!=NULL&&lista!=NULL&&tam>0)
    {
        lugar=buscarTarjeta(lista,num,tam);
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
            printf("\nYA EXISTE ESTA TARJETA!!!!\n");
            flag=-2;
        }
    }
    return flag;
}

int buscarTarjeta(Epropietario lista[],char num[],int tam)
{
    int i;
    int aux=-1;

    if(lista!=NULL&&num!=0&&tam>0)
    {
        aux=-2;
        for(i=0; i<tam; i++)
        {
            if(strcasecmp(num,lista[i].numDeTarjeta)==0)
            {
                aux=i;
                break;
            }
        }
    }

    return aux;
}

int mostrarListaPropietario(Epropietario lista[],int tam)
{
    int i;
    int flag=-1;

    if(lista!=NULL&&tam>0)
    {
        flag=1;
        for(i=0; i<tam; i++)
        {
            if(lista[i].estado==1)
            {
                printf("\nID: %d -- NOMBRE: %s -- APELLIDO: %s -- TARJETA: %s -- DIRECCION: %s\n",lista[i].id,lista[i].nombre,lista[i].apellido,lista[i].numDeTarjeta,lista[i].direccion);
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



void inicializarUsuariosHardCode(Epropietario persona[])
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};

    int i;

    for(i=0; i<4; i++)
    {
        persona[i].id=id[i];
        strcpy(persona[i].nombre, nombre[i]);
        strcpy(persona[i].numDeTarjeta,tarjeta[i]);
        strcpy(persona[i].direccion,direccion[i]);
        persona[i].estado = 1;
    }

}

void modificarPropietario(Epropietario lista[],int lugar)
{
    char modifica;

    printf("ID: %d\nNOMBRE: %s\nTARJETA: %s\n\nDESEA MODIFICAR?[S/N] ",lista[lugar].id,lista[lugar].nombre,lista[lugar].numDeTarjeta);

    modifica=getch();

    if(modifica=='s'||modifica=='S')
    {
        igresoCadenaChar("\nINGRESE TARJETA: ",lista[lugar].numDeTarjeta);
    }
}

int darBajaPersona(Epropietario lista[],int ubicacion)
{
    char borrar;
    int flag=-1;

    if(lista!=NULL&&ubicacion>=0)
    {
        flag=0;
        printf("\n\nQUIERE DAR DE BAJA A ?\n\n NOMBRE: %s -- APELLIDO: %s\n\n",lista[ubicacion].nombre,lista[ubicacion].apellido);
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
        printf("\nEL ID INGRESADO NO SE ENCUENTRA EN LA LISTA!!!!!\n\n");
    }
    return flag;
}

float darTike(Eauto listaAutos[],int tam,int lugar,Epropietario listaPropietarios[],int horas)
{
    float precio;

    horas=devolverHorasEstadia();
    precio=devolverPrecio(listaAutos,lugar);
    precio=multiplicacion(precio,horas);
    //flag=darBajaAuto(listaAutos,lugar);

    mostrarAutoConPropietario(listaAutos,listaPropietarios,lugar,tam);
    printf("PRECIO: $%.2f\n",precio);
    return precio;
}


int buscarAutoDelPropietario(Eauto listaAuto[],Epropietario propietario,int tam)
{
    int i;
    int lugar=-1;

    if(listaAuto!=NULL)
    {
        lugar=-2;
        for(i=0; i<tam; i++)
        {
            if((listaAuto[i].idPropietario==propietario.id)&&(listaAuto[i].estado!=0))
            {
                lugar=i;
                break;
            }
        }
    }

    return lugar;
}

int mostrarListaPropietarioConSusAutos(Epropietario listaPropietarios[],int tamPro,Eauto listaAuto[],int tamAut)
{
    int i,j;
    int flag=-1;
    char marca[20];
    if(listaPropietarios!=NULL&&listaAuto!=NULL&&tamAut>0&&tamPro>0)
    {
        flag=1;
        for(i=0; i<tamPro; i++)
        {
            if(listaPropietarios[i].estado==1)
            {

                printf("PROPIETARIO:\n\nID: %d -- NOMBRE: %s -- APELLIDO: %s \n\n",listaPropietarios[i].id,listaPropietarios[i].nombre,listaPropietarios[i].apellido);
                for(j=0; j<tamAut; j++)
                {
                    if((listaAuto[j].estado==1)&&(listaAuto[j].idPropietario==listaPropietarios[i].id))
                    {
                        devolverMarca(listaAuto[j].marca,marca);
                        printf("AUTOS:\n\nPATENTE: %s -- LUGAR: %d -- MARCA: %s\n",listaAuto[j].patente,listaAuto[j].id,marca);
                    }
                }
                printf("-----------------------------------------------------------\n");
                flag=0;
            }
        }
    }
    return flag;
}
float totalRecaudado(float recauMarcas[],int tam)
{
    float recaudado=0;
    int i;

    for(i=0; i<tam; i++)
    {
        recaudado+=recauMarcas[i];
    }

    printf("RECAUDO TOTAL: %.2f\n\n",recaudado);

    return recaudado;
}

void darBajaTodosLosAutosDelPropietario(Eauto listaAut[],Epropietario propietario,int tamAut,float *acumuladores)
{
    int lugar;
    int horas;
    float precio;
    do
    {
        lugar=buscarAutoDelPropietario(listaAut,propietario,tamAut);
        if(!(lugar<0))
        {
            precio=devolverPrecio(listaAut,lugar);
            listaAut[lugar].estado=0;
            horas=devolverHorasEstadia();
            *(acumuladores+(listaAut[lugar].marca)-1)+=multiplicacion(horas,precio);
        }
    }
    while(lugar>=0);
}
