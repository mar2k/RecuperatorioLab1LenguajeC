
typedef struct
{
    char nombre[20];
    char apellido[20];
    char numDeTarjeta[20];
    char direccion[20];
    int estado;
    int id;

} Epropietario;

typedef struct
{
    char patente[20];
    int idPropietario;
    int marca;
    int estado;
    int id;
}Eauto;


int iniEstadoPersona(Epropietario lista[],int tam);

int obtenerEspacioLibre(Epropietario lista[],int tam);

int validarId(int id,Epropietario lista[],int tam);

int buscarPorIdPersona(Epropietario lista[],int id,int tam);

int cargaDeDatosPersona(Epropietario lista[],int lugar,int tam);

int mostrarListaPropietario(Epropietario lista[],int tam);

int validarTarjeta(char num[],Epropietario lista[],int tam);

int buscarTarjeta(Epropietario lista[],char num[],int tam);

void inicializarUsuariosHardCode(Epropietario persona[]);

void modificarPropietario(Epropietario lista[],int lugar);

int darBajaPersona(Epropietario lista[],int ubicacion);

float darTike(Eauto listaAutos[],int tam,int lugar,Epropietario listaPropietarios[],int horas);

int buscarAutoDelPropietario(Eauto listaAuto[],Epropietario propietario,int tam);

int mostrarListaPropietarioConSusAutos(Epropietario listaPropietarios[],int tamPro,Eauto listaAuto[],int tamAut);

float totalRecaudado(float recauMarcas[],int tam);

void darBajaTodosLosAutosDelPropietario(Eauto listaAut[],Epropietario propietario,int tamAut,float *acumuladores);
