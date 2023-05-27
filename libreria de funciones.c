//////////////// Libreria con el codigo de las funciones





#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "libreria de funciones.h"




void menu_principal(int *opcion)  // Función menu principal con system cls
{
	printf("\nBienvenido al programa de analisis de datos \n\n");

	printf("Que desea realizar:\n\n");

	printf("Informacion sobre programa     1\n");
	printf("Cargar fichero de datos        2\n");
	printf("Salir                          3\n");

	printf("\n");

	scanf("%i", &*opcion);

	system("cls");

	printf("\n");
} // Actualizacion


 

void informacion(int *info)
{
	printf("INFORMACION SOBRE EL PROGRAMA DE ANALISIS DE BASES DE DATOS\n");

	printf("Este programa sirve para realizar una serie de operaciones como calculo,\n busqueda y carga de datos a partir de un archivo de texto de datos\n");

	do
	{
		printf("\n");

		printf("Diversos calculos       1\n");
		printf("Busqueda de datos       2\n");
		printf("Carga resultados        3\n");
		printf("Salir                   4\n");

        printf("\n");

		scanf("%i", &*info);

		system("cls");

		switch (*info)
		{
            case 1:
                printf("\nRealiza diferentes calculos tales como el maximo, minimo y medias\n");
                break;

            case 2:
                printf("\nBusca datos especificos, esto es, buscar un dato en concreto a traves de una fecha\n");
                break;

            case 3:
                printf("\nMuestra por pantalla los datos del archivo\n");
                break;

            case 4:
                printf("\nSaliendo\n");
                break;

            default:
               printf("\nOpcion no disponible\n");
               break;
		}
	}
	while(*info != 4);
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

 


int apertura_lectura_guardardatos(datos valores[], int n)  //comprueba el fichero, lee y guarda los datos en vectores
{
    FILE *fOrigen, *fDestino;

    char c;

    // Abre ficheros:
    // El origen en modo lectura
    fOrigen = fopen("generacion_por_tecnologias_21_22.csv", "r");

    if (fOrigen == NULL)
    {
        printf("Error al abrir el archivo origen.\n");
        return -1;
    }

    else
    {
        // El destino en modo escritura
        fDestino = fopen("generacion.txt", "w");
        if (fDestino == NULL)
        {
            printf("Error al abrir el archivo destino.\n");
            return -1;
        }
        else
        {
            // Leemos el origen caracter por caracter, parando al encontrar el EOF
            while (fscanf(fOrigen, "%c", &c) != EOF)
            {
                if ((c == '/') || (c == '"'))
                {
                    c = ' ';    // Cambiamos barras y comillas por espacios
                }
                else if(c == ',')
                {
                    c = '.';    // Cambiamos comas por puntos
                }

                fprintf(fDestino, "%c", c); // Escribimos el caracter en el destino
            }
            // Cerramos ficheros
            fclose(fDestino);
            fclose(fOrigen);
            printf("Carga finalizada con exito.\n");
        }
    }
 
 // INICIALIZACION DE LA 2º PARTE LEYENDO EL FICHERO MODIFICADO

int i;

    char linea1[200], linea2[200], linea3[200], linea4[200], linea5[200];

    char hidraulica[50], turbinacion_bombeo[25], nuclear[25], carbon[25], fuel_Gas[25], motores_diesel[25], turbina_de_gas[25], turbina_de_vapor[25], ciclo_combinado[25], hidroeolica[25], eolica[25], solar_fotovoltaica[25], solar_termica[25], otras_renovables[25], cogeneracion[25], residuos_no_renovables[25], residuos_renovables[25], generacion_total[25];

    double Hidraulica[30], Turbinacion_bombeo[25], Nuclear[25], Carbon[25], Fuel_Gas[25], Motores_diesel[25], Turbina_de_gas[25], Turbina_de_vapor[25], Ciclo_combinado[25], Hidroeolica[25], Eolica[25], Solar_fotovoltaica[25], Solar_termica[25], Otras_renovables[25], Cogeneracion[25], Residuos_no_renovables[25], Residuos_renovables[25], Generacion_total[25];

    char Fecha[20];

    int fecha[25];

    FILE *pleer;

    pleer = fopen("generacion.txt", "r");

    if (pleer == NULL)
    {
        printf("Error al abrir el fichero.\n");
        return -1;
    }
    else
    {
        fscanf(pleer, "%[^\n]\n", linea1);    //salto fila 1
        fscanf(pleer, "%[^\n]\n", linea2);    //salto fila 2
        fscanf(pleer, "%[^\n]\n", linea3);    //salto fila 3
        fscanf(pleer, "%[^\n]\n", linea4);    //salto fila 4
        fscanf(pleer, "%[^\n]\n", linea5);    //salto fila 5  fechas

        //fscanf(pleer, "%[^.].%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i\n", Fecha, &fecha[0],&fecha[1],&fecha[2],&fecha[3],&fecha[4],&fecha[5],&fecha[6],&fecha[7],&fecha[8],&fecha[9],&fecha[10],&fecha[11],&fecha[12],&fecha[13],&fecha[14],&fecha[15],&fecha[16],&fecha[17],&fecha[18],&fecha[19],&fecha[20],&fecha[21],&fecha[22],&fecha[23],&fecha[25],&fecha[25]);

        fscanf(pleer, "%[^.]. %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf \n", hidraulica, &Hidraulica[1], &Hidraulica[2],&Hidraulica[3],&Hidraulica[4],&Hidraulica[5],&Hidraulica[6],&Hidraulica[7],&Hidraulica[8],&Hidraulica[9],&Hidraulica[10],&Hidraulica[11],&Hidraulica[12],&Hidraulica[13],&Hidraulica[14],&Hidraulica[15],&Hidraulica[16],&Hidraulica[17],&Hidraulica[18],&Hidraulica[19],&Hidraulica[20],&Hidraulica[21],&Hidraulica[22],&Hidraulica[23],&Hidraulica[24],&Hidraulica[25]);

        fscanf(pleer, "%[^.]. %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf \n", turbinacion_bombeo, &Turbinacion_bombeo[1], &Turbinacion_bombeo[2],&Turbinacion_bombeo[3],&Turbinacion_bombeo[4],&Turbinacion_bombeo[5],&Turbinacion_bombeo[6],&Turbinacion_bombeo[7],&Turbinacion_bombeo[8],&Turbinacion_bombeo[9],&Turbinacion_bombeo[10],&Turbinacion_bombeo[11],&Turbinacion_bombeo[12],&Turbinacion_bombeo[13],&Turbinacion_bombeo[14],&Turbinacion_bombeo[15],&Turbinacion_bombeo[16],&Turbinacion_bombeo[17],&Turbinacion_bombeo[18],&Turbinacion_bombeo[19],&Turbinacion_bombeo[20],&Turbinacion_bombeo[21],&Turbinacion_bombeo[22],&Turbinacion_bombeo[23],&Turbinacion_bombeo[24],&Turbinacion_bombeo[25]);

        fscanf(pleer, "%[^.]. %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf \n", nuclear, &Nuclear[1], &Nuclear[2],&Nuclear[3],&Nuclear[4],&Nuclear[5],&Nuclear[6],&Nuclear[7],&Nuclear[8],&Nuclear[9],&Nuclear[10],&Nuclear[11],&Nuclear[12],&Nuclear[13],&Nuclear[14],&Nuclear[15],&Nuclear[16],&Nuclear[17],&Nuclear[18],&Nuclear[19],&Nuclear[20],&Nuclear[21],&Nuclear[22],&Nuclear[23],&Nuclear[24],&Nuclear[25]);
  
        printf("%s\n", linea1);
        printf("%s\n", linea2);
        printf("%s\n", linea3);
        printf("%s\n", linea4);
        printf("%s\n", linea5);


        printf("\n");

        printf("%s \n", hidraulica);

        for(i=1;i<25;i++)
        {
            printf("%lf ", Hidraulica[i]);
        }

        printf("\n\n");

        printf("%s \n", turbinacion_bombeo);
        for(i=1;i<25;i++)
        {
            printf("%lf ", Turbinacion_bombeo[i]);
        }

        printf("\n\n");

        printf("%s \n", nuclear);
        for(i=1;i<25;i++)
        {
            printf("%lf ", Nuclear[i]);
        }

        printf("\n\n");
     
     fclose(pleer);
 
 
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
