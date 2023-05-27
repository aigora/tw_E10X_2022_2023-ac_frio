typedef struct     //estructura para el nombre del tipo de energia
{
    char tipo[50];
    int fecha;
    float generacion[50];

 

}energia;

 

 


void menu_principal(int *opcion);       //funcion del menu principal

 

void informacion(int *info);            //funcion para la informacion sobre el programa

 

void menu_secundario(int *seleccion);   //funcion menu secundario

 

int comprobar_existencia_fichero();     //funcion comprobar fichero y lectura de datos

 

void cargar_fichero();

 

int crear_nuevo_fichero();

 

void diversos_calculos();               //funcion realza los calculos
