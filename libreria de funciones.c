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

	char fecha[25];

    char linea1[200], linea2[200], linea3[200], linea4[200];

    char hidraulica[25], turbinacion_bombeo[25], nuclear[25], carbon[25], fuel_Gas[25], motores_diesel[25], turbina_de_gas[25], turbina_de_vapor[25], ciclo_combinado[25], hidroeolica[25], eolica[25], solar_fotovoltaica[25], solar_termica[25], otras_renovables[25], cogeneracion[25], residuos_no_renovables[25], residuos_renovables[25], generacion_total[25];

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

        //fscanf(pleer, "%[^.].%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i.%i\n", Fecha, &fecha[0],&fecha[1],&fecha[2],&fecha[3],&fecha[4],&fecha[5],&fecha[6],&fecha[7],&fecha[8],&fecha[9],&fecha[10],&fecha[11],&fecha[12],&fecha[13],&fecha[14],&fecha[15],&fecha[16],&fecha[17],&fecha[18],&fecha[19],&fecha[20],&fecha[21],&fecha[22],&fecha[23],&fecha[25],&fecha[25]);

        //fscanf(pleer, "%[^.]. %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf . %lf \n", hidraulica, &Hidraulica[1], &Hidraulica[2],&Hidraulica[3],&Hidraulica[4],&Hidraulica[5],&Hidraulica[6],&Hidraulica[7],&Hidraulica[8],&Hidraulica[9],&Hidraulica[10],&Hidraulica[11],&Hidraulica[12],&Hidraulica[13],&Hidraulica[14],&Hidraulica[15],&Hidraulica[16],&Hidraulica[17],&Hidraulica[18],&Hidraulica[19],&Hidraulica[20],&Hidraulica[21],&Hidraulica[22],&Hidraulica[23],&Hidraulica[24],&Hidraulica[25]);

		fscanf(pleer, "%[^.].", fecha);

		for(i = 0; i < 9; i++)
		{
			fscanf(pleer,"0%i %i.", &valores[i].mes, &valores[i].ano);
		}
		fscanf(pleer,"%i %i.%i %i.%i %i.", &valores[9].mes, &valores[9].ano, &valores[10].mes, &valores[10].ano, &valores[11].mes, &valores[11].ano);

		for(i = 12; i < 21; i++)
		{
			fscanf(pleer,"0%i %i.", &valores[i].mes, &valores[i].ano);
		}
		fscanf(pleer,"%i %i.%i %i.%i %i\n", &valores[21].mes, &valores[21].ano, &valores[22].mes, &valores[22].ano, &valores[23].mes, &valores[23].ano);


		fscanf(pleer, "%[^.]", hidraulica);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Hidraulica);
		}


		fscanf(pleer, "%[^.]", turbinacion_bombeo);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Turbinacion_bombeo);
		}


		fscanf(pleer, "%[^.]", nuclear);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Nuclear);
		}


		fscanf(pleer, "%[^.]", carbon);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Carbon);
		}


		fscanf(pleer, "%[^.]", fuel_Gas);

		for(i = 0; i < 6; i++)
		{
			fscanf(pleer,". %c ", &valores[i].Fuel_gasc);
		}

		fscanf(pleer,". %lf ", &valores[6].Fuel_gas);

		for(i = 7; i < 24; i++)
		{
			fscanf(pleer,". %c ", &valores[i].Fuel_gasc);
		}


		fscanf(pleer, "%[^.]", motores_diesel);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Motores_diesel);
		}


		fscanf(pleer, "%[^.]", turbina_de_gas);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Turbina_gas);
		}


		fscanf(pleer, "%[^.]", turbina_de_vapor);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Turbina_vapor);
		}


		fscanf(pleer, "%[^.]", ciclo_combinado);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Ciclo_combinado);
		}


		fscanf(pleer, "%[^.]", hidroeolica);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Hidroeolica);
		}


		fscanf(pleer, "%[^.]", eolica);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Eolica);
		}


		fscanf(pleer, "%[^.]", solar_fotovoltaica);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Solar_fotovoltaica);
		}


		fscanf(pleer, "%[^.]", solar_termica);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Solar_termica);
		}


		fscanf(pleer, "%[^.]", otras_renovables);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Otras_renovables);
		}


		fscanf(pleer, "%[^.]", cogeneracion);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Cogeneracion);
		}


		fscanf(pleer, "%[^.]", residuos_no_renovables);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Residuos_no_renovables);
		}


		fscanf(pleer, "%[^.]", residuos_renovables);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Residuos_renovables);
		}


		fscanf(pleer, "%[^.]", generacion_total);

		for(i = 0; i < 24; i++)
		{
			fscanf(pleer,". %lf ", &valores[i].Generacion_total);
		}


        fclose(pleer);
        return 0;
	}
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
