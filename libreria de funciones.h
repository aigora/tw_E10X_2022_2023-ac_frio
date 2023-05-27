//////////////// Libreria con las cabezeras de las funciones y las estructuras


typedef struct    //estructura para el nombre del tipo de energia
{
    int mes;
	int ano;
	double Hidraulica; //RENOVABLE
	double Turbinacion_bombeo; //RENOVABLE
	double Nuclear; //RENOVABLE
	double Carbon; //NO RENOVABLE
	char Fuel_gasc; 
	double Fuel_gas; //NO RENOVABLE
	double Motores_diesel; //NO RENOVABLE
	double Turbina_gas; //MEZCLA
	double Turbina_vapor; //MEZCLA
	double Ciclo_combinado; //MEZCLA
	double Hidroeolica; //RENOVABLE
	double Eolica; //RENOVABLE
	double Solar_fotovoltaica; //RENOVABLE
	double Solar_termica; //RENOVABLE
	double Otras_renovables; //RENOVABLE
	double Cogeneracion; //MEZCLA
	double Residuos_no_renovables; //RESIDUOS
	double Residuos_renovables; //RESIDUOS
	double Generacion_total; 
}datos;




void menu_principal(int *opcion);       //funcion del menu principal

void informacion(int *info);            //funcion para la informacion sobre el programa

void menu_secundario(int *seleccion, datos valores[]);   //funcion menu secundario

int apertura_lectura_guardardatos(datos valores[], int n);     //funcion comprobar fichero y lectura de datos

void diversos_calculos(datos valores[], int n);               //funcion realiza los calculos

void cargar_resultados(datos valores[], int n);               //funcion realiza carga de datos

void busqueda_resultados(datos valores[], int n);               //funcion realiza busqueda de datos
