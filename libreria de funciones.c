//////////////// Libreria con el codigo de las funciones

 

 

 

#include <stdio.h>
#include "libreria de funciones.h"

 

 


void menu_principal(int *opcion)
{
    //system("cls");  //Borrar pantalla o no, para poder mirar cuando se quiera las instruciones

 

    printf("\nBienvenido al programa de analisis de datos \n\n");

 

    printf("Que desea realizar:\n\n");

 

    printf("informacionn sobre programa    1\n");
    printf("cargar fichero de datos        2\n");
    printf("salir                          3\n");

 

    //fflush(stdin);
    scanf("%i", &*opcion);
}

 

void informacion(int *info)
{
    printf("\nIFORMACION SOBRE EL PROGRAMA DE ANALISIS DE BASES DE DATOS\n");

 

    printf("Este programa se dedica a realizar una serie de operaciones como calculo de datos, busqueda, orenacion, etc, a partir de uno (o mas) archivos de texto de datos\n");

 

    do
    {
        printf("\n");

 

        printf("diversos calculos       1\n");
        printf("carga de nuevos datos   2\n");
        printf("guardar resultados      3\n");
        printf("busqueda de datos       4\n");
        printf("ordenar resultados      5\n");
        printf("salir                   6\n");

 

        //fflush(stdin);

 

        scanf("%i", &*info);

 

        switch (*info)
        {
            case 1:
                printf("realiza diferentes calculos estadisticos\n");
                break;

 

            case 2:
                printf("añade nuevos datos\n");
                break;

 

            case 3:
                printf("guarda nuevos resultados\n");
                break;

 

            case 4:
                printf("busca datos especificos\n");
                break;

 

            case 5:
                printf("ordena resultados en orden ascendente\n");
                break;

 

            case 6:
                printf("saliendo\n");
                break;

 

            default:
               printf("opcion no disponible\n");
               break;
        }
    }

 

    while(*info != 6);

 

    //system("PAUSE");

 

}

 


void menu_secundario(int *seleccion)
{
    printf("que operacion desea realizar\n\n");

 

    do
    {
        printf("diversos calculos       1\n");
        printf("carga de nuevos datos   2\n");
        printf("guardar resultados      3\n");
        printf("busqueda de datos       4\n");
        printf("ordenar resultados      5\n");
        printf("salir                   6\n");

 

        //fflush(stdin);

 

        scanf("%i", &*seleccion);

 

        switch (*seleccion)
        {
            case 1:
                printf("\n");

 

                break;

 

            case 2:
                printf("\n");

 

                break;

 

            case 3:
                printf("\n");

 

                break;

 

            case 4:
                printf("\n");

 

                break;

 

            case 5:
                printf("\n");

 

                break;

 

            case 6:
                printf("saliendo\n");
                break;

 

            default:
               printf("opcion no disponible\n");
               break;
        }
    }

 

    while(*seleccion != 6);

 

    system("PAUSE");
}

 


int comprobar_existencia_fichero()  //comprueba el fichero y guarda los datos en vectores
{
    FILE *pf;

 

    pf = fopen("generacion_por_tecnologias_21_22.csv", "r");

 

    if (pf == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
    {
        printf("Fichero abierto correctamente.\n");

 

        //leer datos fichero y guardarlo en vectores

 

 


        return 0;
    }
    fclose(pf);
}

 

void cargar_fichero()
{

 

}

 

int crear_nuevo_fichero()
{

 

}

 

void diversos_calculos()
{

 

}
