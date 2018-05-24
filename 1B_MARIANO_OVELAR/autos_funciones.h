
void inicializarAutosHardCode(Eauto lista[]);

int obtenerEspacioLibreEstacionamiento(Eauto lista[],int tam);

int cargaDeDatosAuto(Eauto lista[],Epropietario listaPro[],int lugar,int tam,int tamPro);

int validarPatente(char dato[],Eauto lista[],int tam);

float devolverPrecio(Eauto listaAuto[],int lugar);

int buscarPatente(Eauto lista[],char dato[],int tam);

int iniEstadoAuto(Eauto lista[],int tam);

int darBajaAuto(Eauto lista[],int ubicacion);

void devolverMarca(int marca,char dato[]);

void mostrarAutoConPropietario(Eauto listaAuto[],Epropietario listaPropietario[],int lugarAuto,int tamPropietarios);

int mostrarListaAutos(Eauto lista[],int tam);

int seleccionarMarcar();

void recaudacionPorMarca(float *recaudaciones,int tam);

void listaAutosDeUnaMarca(Eauto listaAut[],int tamAut,Epropietario listPro[],int tamPro,int numMarca);

int mostrarListaAutosConSusPropietrios(Epropietario listaPropietarios[],int tamPro,Eauto listaAuto[],int tamAut);

void ordenarPatentes(Eauto listaAut[],int tam);
