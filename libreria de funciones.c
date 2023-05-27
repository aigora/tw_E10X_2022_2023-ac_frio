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

 

void diversos_calculos(datos valores[], int n)
{
    int i;

    int chose;

    double sumatorio_hidraulica = 0, max_hidraulica= valores[0].Hidraulica, min_hidraulica= valores[0].Hidraulica;
	int mesmax_hidraulica = 0, anomax_hidraulica = 0, mesmin_hidraulica = 0, anomin_hidraulica = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_hidraulica += valores[i].Hidraulica;
    }

    for(i = 0; i < n; i++)
    {
        if(max_hidraulica <= valores[i].Hidraulica)
        {
            max_hidraulica = valores[i].Hidraulica;
            mesmax_hidraulica = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_hidraulica >= valores[i].Hidraulica)
        {
            min_hidraulica = valores[i].Hidraulica;
            mesmin_hidraulica = i+1;
        }
    }

	if(mesmax_hidraulica <=  12)
    {
    	anomax_hidraulica = 2021;
	}
	if((mesmax_hidraulica > 12) && (mesmax_hidraulica <= 24))
	{
		mesmax_hidraulica = mesmax_hidraulica - 12;
		anomax_hidraulica = 2022;
	}

	if(mesmin_hidraulica <=  12)
    {
    	anomin_hidraulica = 2021;
	}
	if((mesmin_hidraulica > 12) && (mesmin_hidraulica <= 24))
	{
		mesmin_hidraulica = mesmin_hidraulica - 12;
		anomin_hidraulica = 2022;
	}
/*
    printf("El total producido de hidraulica en 2 años es: %lf\n", sumatorio_hidraulica);
    printf("La media mensual producida de hidraulica en 2 años es: %lf\n", sumatorio_hidraulica/24);
    printf("La media anual producida de hidraulica en 2 años es: %lf\n", sumatorio_hidraulica/2);
    printf("El maximo producido de hidraulica en 2 años ocurre en %i %i es: %lf\n", mesmax_hidraulica, anomax_hidraulica, max_hidraulica);
    printf("El minimo producido de hidraulica en 2 años ocurre en %i %i es: %lf\n\n", mesmin_hidraulica, anomin_hidraulica, min_hidraulica);
*/

    double sumatorio_turbinacion_bombeo = 0, max_turbinacion_bombeo = valores[0].Turbinacion_bombeo, min_turbinacion_bombeo = valores[0].Turbinacion_bombeo;
	int mesmax_turbinacion_bombeo = 0, anomax_turbinacion_bombeo = 0, mesmin_turbinacion_bombeo = 0, anomin_turbinacion_bombeo = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_turbinacion_bombeo += valores[i].Turbinacion_bombeo;
    }

    for(i = 0; i < n; i++)
    {
        if(max_turbinacion_bombeo <= valores[i].Turbinacion_bombeo)
        {
            max_turbinacion_bombeo = valores[i].Turbinacion_bombeo;
            mesmax_turbinacion_bombeo = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_turbinacion_bombeo >= valores[i].Turbinacion_bombeo)
        {
            min_turbinacion_bombeo = valores[i].Turbinacion_bombeo;
            mesmin_turbinacion_bombeo = i+1;
        }
    }

	if(mesmax_turbinacion_bombeo <=  12)
    {
    	anomax_turbinacion_bombeo = 2021;
	}
	if((mesmax_turbinacion_bombeo > 12) && (mesmax_turbinacion_bombeo <= 24))
	{
		mesmax_turbinacion_bombeo = mesmax_turbinacion_bombeo - 12;
		anomax_turbinacion_bombeo = 2022;
	}

	if(mesmin_turbinacion_bombeo <=  12)
    {
    	anomin_turbinacion_bombeo = 2021;
	}
	if((mesmin_turbinacion_bombeo > 12) && (mesmin_turbinacion_bombeo <= 24))
	{
		mesmin_turbinacion_bombeo = mesmin_turbinacion_bombeo - 12;
		anomin_turbinacion_bombeo = 2022;
	}
/*
    printf("El total producido de turbinacion_bombeo en 2 años es: %lf\n", sumatorio_turbinacion_bombeo);
    printf("La media mensual producida de turbinacion_bombeo en 2 años es: %lf\n", sumatorio_turbinacion_bombeo/24);
    printf("La media anual producida de turbinacion_bombeo en 2 años es: %lf\n", sumatorio_turbinacion_bombeo/2);
    printf("El maximo producido de turbinacion_bombeo en 2 años ocurre en %i %i es: %lf\n", mesmax_turbinacion_bombeo, anomax_turbinacion_bombeo, max_turbinacion_bombeo);
    printf("El minimo producido de turbinacion_bombeo en 2 años ocurre en %i %i es: %lf\n\n", mesmin_turbinacion_bombeo, anomin_turbinacion_bombeo, min_turbinacion_bombeo);
*/

    double sumatorio_nuclear = 0, max_nuclear = valores[0].Nuclear, min_nuclear = valores[0].Nuclear;
	int mesmax_nuclear = 0, anomax_nuclear = 0, mesmin_nuclear = 0, anomin_nuclear = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_nuclear += valores[i].Nuclear;
    }

    for(i = 0; i < n; i++)
    {
        if(max_nuclear <= valores[i].Nuclear)
        {
            max_nuclear = valores[i].Nuclear;
            mesmax_nuclear = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_nuclear >= valores[i].Nuclear)
        {
            min_nuclear = valores[i].Nuclear;
            mesmin_nuclear = i+1;
        }
    }

	if(mesmax_nuclear <=  12)
    {
    	anomax_nuclear = 2021;
	}
	if((mesmax_nuclear > 12) && (mesmax_nuclear <= 24))
	{
		mesmax_nuclear = mesmax_nuclear - 12;
		anomax_nuclear = 2022;
	}

	if(mesmin_nuclear <=  12)
    {
    	anomin_nuclear = 2021;
	}
	if((mesmin_nuclear > 12) && (mesmin_nuclear <= 24))
	{
		mesmin_nuclear = mesmin_nuclear - 12;
		anomin_nuclear = 2022;
	}
/*
    printf("El total producido de nuclear en 2 años es: %lf\n", sumatorio_nuclear);
    printf("La media mensual producida de nuclear en 2 años es: %lf\n", sumatorio_nuclear/24);
    printf("La media anual producida de nuclear en 2 años es: %lf\n", sumatorio_nuclear/2);
    printf("El maximo producido de nuclear en 2 años ocurre en %i %i es: %lf\n", mesmax_nuclear, anomax_nuclear, max_nuclear);
    printf("El minimo producido de nuclear en 2 años ocurre en %i %i es: %lf\n\n", mesmin_nuclear, anomin_nuclear, min_nuclear);
*/

    double sumatorio_carbon = 0, max_carbon = valores[0].Carbon, min_carbon = valores[0].Carbon;
	int mesmax_carbon = 0, anomax_carbon = 0, mesmin_carbon = 0, anomin_carbon = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_carbon += valores[i].Carbon;
    }

    for(i = 0; i < n; i++)
    {
        if(max_carbon <= valores[i].Carbon)
        {
            max_carbon = valores[i].Carbon;
            mesmax_carbon = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_carbon >= valores[i].Carbon)
        {
            min_carbon = valores[i].Carbon;
            mesmin_carbon = i+1;
        }
    }

	if(mesmax_carbon <=  12)
    {
    	anomax_carbon = 2021;
	}
	if((mesmax_carbon > 12) && (mesmax_carbon <= 24))
	{
		mesmax_carbon = mesmax_carbon - 12;
		anomax_carbon = 2022;
	}

	if(mesmin_carbon <=  12)
    {
    	anomin_carbon = 2021;
	}
	if((mesmin_carbon > 12) && (mesmin_carbon <= 24))
	{
		mesmin_carbon = mesmin_carbon - 12;
		anomin_carbon = 2022;
	}
/*
    printf("El total producido de carbon en 2 años es: %lf\n", sumatorio_carbon);
    printf("La media mensual producida de carbon en 2 años es: %lf\n", sumatorio_carbon/24);
    printf("La media anual producida de carbon en 2 años es: %lf\n", sumatorio_carbon/2);
    printf("El maximo producido de carbon en 2 años ocurre en %i %i es: %lf\n", mesmax_carbon, anomax_carbon, max_carbon);
    printf("El minimo producido de carbon en 2 años ocurre en %i %i es: %lf\n\n", mesmin_carbon, anomin_carbon, min_carbon);
*/

    double sumatorio_fuel_Gas = 0, max_fuel_Gas = valores[0].Fuel_gas, min_fuel_Gas = valores[0].Fuel_gas;
	int mesmax_fuel_Gas = 0, anomax_fuel_Gas = 0, mesmin_fuel_Gas = 0, anomin_fuel_Gas = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_fuel_Gas += valores[i].Fuel_gas;
    }

    for(i = 0; i < n; i++)
    {
        if(max_fuel_Gas <= valores[i].Fuel_gas)
        {
            max_fuel_Gas = valores[i].Fuel_gas;
            mesmax_fuel_Gas = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_fuel_Gas >= valores[i].Fuel_gas)
        {
            min_fuel_Gas = valores[i].Fuel_gas;
            mesmin_fuel_Gas = i+1;
        }
    }

	if(mesmax_fuel_Gas <=  12)
    {
    	anomax_fuel_Gas = 2021;
	}
	if((mesmax_fuel_Gas > 12) && (mesmax_fuel_Gas <= 24))
	{
		mesmax_fuel_Gas = mesmax_fuel_Gas - 12;
		anomax_fuel_Gas = 2022;
	}

	if(mesmin_fuel_Gas <=  12)
    {
    	anomin_fuel_Gas = 2021;
	}
	if((mesmin_fuel_Gas > 12) && (mesmin_fuel_Gas <= 24))
	{
		mesmin_fuel_Gas = mesmin_fuel_Gas - 12;
		anomin_fuel_Gas = 2022;
	}
/*
    printf("El total producido de fuel_Gas en 2 años es: %lf\n", sumatorio_fuel_Gas);
    printf("La media mensual producida de fuel_Gas en 2 años es: %lf\n", sumatorio_fuel_Gas/24);
    printf("La media anual producida de fuel_Gas en 2 años es: %lf\n", sumatorio_fuel_Gas/2);
    printf("El maximo producido de fuel_Gas en 2 años ocurre en %i %i es: %lf\n", mesmax_fuel_Gas, anomax_fuel_Gas, max_fuel_Gas);
    printf("El minimo producido de fuel_Gas en 2 años ocurre en %i %i es: %lf\n\n", mesmin_fuel_Gas, anomin_fuel_Gas, min_fuel_Gas);
*/

    double sumatorio_motores_diesel = 0, max_motores_diesel = valores[0].Motores_diesel, min_motores_diesel = valores[0].Motores_diesel;
	int mesmax_motores_diesel = 0, anomax_motores_diesel = 0, mesmin_motores_diesel = 0, anomin_motores_diesel = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_motores_diesel += valores[i].Motores_diesel;
    }

    for(i = 0; i < n; i++)
    {
        if(max_motores_diesel <= valores[i].Motores_diesel)
        {
            max_motores_diesel = valores[i].Motores_diesel;
            mesmax_motores_diesel = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_motores_diesel >= valores[i].Motores_diesel)
        {
            min_motores_diesel = valores[i].Motores_diesel;
            mesmin_motores_diesel = i+1;
        }
    }

	if(mesmax_motores_diesel <=  12)
    {
    	anomax_motores_diesel = 2021;
	}
	if((mesmax_motores_diesel > 12) && (mesmax_motores_diesel <= 24))
	{
		mesmax_motores_diesel = mesmax_motores_diesel - 12;
		anomax_motores_diesel = 2022;
	}

	if(mesmin_motores_diesel <=  12)
    {
    	anomin_motores_diesel = 2021;
	}
	if((mesmin_motores_diesel > 12) && (mesmin_motores_diesel <= 24))
	{
		mesmin_motores_diesel = mesmin_motores_diesel - 12;
		anomin_motores_diesel = 2022;
	}
/*
    printf("El total producido de motores_diesel en 2 años es: %lf\n", sumatorio_motores_diesel);
    printf("La media mensual producida de motores_diesel en 2 años es: %lf\n", sumatorio_motores_diesel/24);
    printf("La media anual producida de motores_diesel en 2 años es: %lf\n", sumatorio_motores_diesel/2);
    printf("El maximo producido de motores_diesel en 2 años ocurre en %i %i es: %lf\n", mesmax_motores_diesel, anomax_motores_diesel, max_motores_diesel);
    printf("El minimo producido de motores_diesel en 2 años ocurre en %i %i es: %lf\n\n", mesmin_motores_diesel, anomin_motores_diesel, min_motores_diesel);
*/

    double sumatorio_turbina_de_gas = 0, max_turbina_de_gas = valores[0].Turbina_gas, min_turbina_de_gas = valores[0].Turbina_gas;
	int mesmax_turbina_de_gas = 0, anomax_turbina_de_gas = 0, mesmin_turbina_de_gas = 0, anomin_turbina_de_gas = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_turbina_de_gas += valores[i].Turbina_gas;
    }

    for(i = 0; i < n; i++)
    {
        if(max_turbina_de_gas <= valores[i].Turbina_gas)
        {
            max_turbina_de_gas = valores[i].Turbina_gas;
            mesmax_turbina_de_gas = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_turbina_de_gas >= valores[i].Turbina_gas)
        {
            min_turbina_de_gas = valores[i].Turbina_gas;
            mesmin_turbina_de_gas = i+1;
        }
    }

	if(mesmax_turbina_de_gas <=  12)
    {
    	anomax_turbina_de_gas = 2021;
	}
	if((mesmax_turbina_de_gas > 12) && (mesmax_turbina_de_gas <= 24))
	{
		mesmax_turbina_de_gas = mesmax_turbina_de_gas - 12;
		anomax_turbina_de_gas = 2022;
	}

	if(mesmin_turbina_de_gas <=  12)
    {
    	anomin_turbina_de_gas = 2021;
	}
	if((mesmin_turbina_de_gas > 12) && (mesmin_turbina_de_gas <= 24))
	{
		mesmin_turbina_de_gas = mesmin_turbina_de_gas - 12;
		anomin_turbina_de_gas = 2022;
	}
/*
    printf("El total producido de turbina_de_gas en 2 años es: %lf\n", sumatorio_turbina_de_gas);
    printf("La media mensual producida de turbina_de_gas en 2 años es: %lf\n", sumatorio_turbina_de_gas/24);
    printf("La media anual producida de turbina_de_gas en 2 años es: %lf\n", sumatorio_turbina_de_gas/2);
    printf("El maximo producido de turbina_de_gas en 2 años ocurre en %i %i es: %lf\n", mesmax_turbina_de_gas, anomax_turbina_de_gas, max_turbina_de_gas);
    printf("El minimo producido de turbina_de_gas en 2 años ocurre en %i %i es: %lf\n\n", mesmin_turbina_de_gas, anomin_turbina_de_gas, min_turbina_de_gas);
*/
 
    double sumatorio_turbina_de_vapor = 0, max_turbina_de_vapor = valores[0].Turbina_vapor, min_turbina_de_vapor = valores[0].Turbina_vapor;
	int mesmax_turbina_de_vapor = 0, anomax_turbina_de_vapor = 0, mesmin_turbina_de_vapor = 0, anomin_turbina_de_vapor = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_turbina_de_vapor += valores[i].Turbina_vapor;
    }

    for(i = 0; i < n; i++)
    {
        if(max_turbina_de_vapor <= valores[i].Turbina_vapor)
        {
            max_turbina_de_vapor = valores[i].Turbina_vapor;
            mesmax_turbina_de_vapor = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_turbina_de_vapor >= valores[i].Turbina_vapor)
        {
            min_turbina_de_vapor = valores[i].Turbina_vapor;
            mesmin_turbina_de_vapor = i+1;
        }
    }

	if(mesmax_turbina_de_vapor <=  12)
    {
    	anomax_turbina_de_vapor = 2021;
	}
	if((mesmax_turbina_de_vapor > 12) && (mesmax_turbina_de_vapor <= 24))
	{
		mesmax_turbina_de_vapor = mesmax_turbina_de_vapor - 12;
		anomax_turbina_de_vapor = 2022;
	}

	if(mesmin_turbina_de_vapor <=  12)
    {
    	anomin_turbina_de_vapor = 2021;
	}
	if((mesmin_turbina_de_vapor > 12) && (mesmin_turbina_de_vapor <= 24))
	{
		mesmin_turbina_de_vapor = mesmin_turbina_de_vapor - 12;
		anomin_turbina_de_vapor = 2022;
	}
/*
    printf("El total producido de turbina_de_vapor en 2 años es: %lf\n", sumatorio_turbina_de_vapor);
    printf("La media mensual producida de turbina_de_vapor en 2 años es: %lf\n", sumatorio_turbina_de_vapor/24);
    printf("La media anual producida de turbina_de_vapor en 2 años es: %lf\n", sumatorio_turbina_de_vapor/2);
    printf("El maximo producido de turbina_de_vapor en 2 años ocurre en %i %i es: %lf\n", mesmax_turbina_de_vapor, anomax_turbina_de_vapor, max_turbina_de_vapor);
    printf("El minimo producido de turbina_de_vapor en 2 años ocurre en %i %i es: %lf\n\n", mesmin_turbina_de_vapor, anomin_turbina_de_vapor, min_turbina_de_vapor);
*/

    double sumatorio_ciclo_combinado = 0, max_ciclo_combinado = valores[0].Ciclo_combinado, min_ciclo_combinado = valores[0].Ciclo_combinado;
	int mesmax_ciclo_combinado = 0, anomax_ciclo_combinado = 0, mesmin_ciclo_combinado = 0, anomin_ciclo_combinado = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_ciclo_combinado += valores[i].Ciclo_combinado;
    }

    for(i = 0; i < n; i++)
    {
        if(max_ciclo_combinado <= valores[i].Ciclo_combinado)
        {
            max_ciclo_combinado = valores[i].Ciclo_combinado;
            mesmax_ciclo_combinado = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_ciclo_combinado >= valores[i].Ciclo_combinado)
        {
            min_ciclo_combinado = valores[i].Ciclo_combinado;
            mesmin_ciclo_combinado = i+1;
        }
    }

	if(mesmax_ciclo_combinado <=  12)
    {
    	anomax_ciclo_combinado = 2021;
	}
	if((mesmax_ciclo_combinado > 12) && (mesmax_ciclo_combinado <= 24))
	{
		mesmax_ciclo_combinado = mesmax_ciclo_combinado - 12;
		anomax_ciclo_combinado = 2022;
	}

	if(mesmin_ciclo_combinado <=  12)
    {
    	anomin_ciclo_combinado = 2021;
	}
	if((mesmin_ciclo_combinado > 12) && (mesmin_ciclo_combinado <= 24))
	{
		mesmin_ciclo_combinado = mesmin_ciclo_combinado - 12;
		anomin_ciclo_combinado = 2022;
	}
/*
    printf("El total producido de ciclo_combinado en 2 años es: %lf\n", sumatorio_ciclo_combinado);
    printf("La media mensual producida de ciclo_combinado en 2 años es: %lf\n", sumatorio_ciclo_combinado/24);
    printf("La media anual producida de ciclo_combinado en 2 años es: %lf\n", sumatorio_ciclo_combinado/2);
    printf("El maximo producido de ciclo_combinado en 2 años ocurre en %i %i es: %lf\n", mesmax_ciclo_combinado, anomax_ciclo_combinado, max_ciclo_combinado);
    printf("El minimo producido de ciclo_combinado en 2 años ocurre en %i %i es: %lf\n\n", mesmin_ciclo_combinado, anomin_ciclo_combinado, min_ciclo_combinado);
*/

    double sumatorio_hidroeolica = 0, max_hidroeolica = valores[0].Hidroeolica, min_hidroeolica = valores[0].Hidroeolica;
	int mesmax_hidroeolica = 0, anomax_hidroeolica = 0, mesmin_hidroeolica = 0, anomin_hidroeolica = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_hidroeolica += valores[i].Hidroeolica;
    }

    for(i = 0; i < n; i++)
    {
        if(max_hidroeolica <= valores[i].Hidroeolica)
        {
            max_hidroeolica = valores[i].Hidroeolica;
            mesmax_hidroeolica = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_hidroeolica >= valores[i].Hidroeolica)
        {
            min_hidroeolica = valores[i].Hidroeolica;
            mesmin_hidroeolica = i+1;
        }
    }

	if(mesmax_hidroeolica <=  12)
    {
    	anomax_hidroeolica = 2021;
	}
	if((mesmax_hidroeolica > 12) && (mesmax_hidroeolica <= 24))
	{
		mesmax_hidroeolica = mesmax_hidroeolica - 12;
		anomax_hidroeolica = 2022;
	}

	if(mesmin_hidroeolica <=  12)
    {
    	anomin_hidroeolica = 2021;
	}
	if((mesmin_hidroeolica > 12) && (mesmin_hidroeolica <= 24))
	{
		mesmin_hidroeolica = mesmin_hidroeolica - 12;
		anomin_hidroeolica = 2022;
	}
/*
    printf("El total producido de hidroeolica en 2 años es: %lf\n", sumatorio_hidroeolica);
    printf("La media mensual producida de hidroeolica en 2 años es: %lf\n", sumatorio_hidroeolica/24);
    printf("La media anual producida de hidroeolica en 2 años es: %lf\n", sumatorio_hidroeolica/2);
    printf("El maximo producido de hidroeolica en 2 años ocurre en %i %i es: %lf\n", mesmax_hidroeolica, anomax_hidroeolica, max_hidroeolica);
    printf("El minimo producido de hidroeolica en 2 años ocurre en %i %i es: %lf\n\n", mesmin_hidroeolica, anomin_hidroeolica, min_hidroeolica);
*/

    double sumatorio_eolica = 0, max_eolica = valores[0].Eolica, min_eolica = valores[0].Eolica;
	int mesmax_eolica = 0, anomax_eolica = 0, mesmin_eolica = 0, anomin_eolica = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_eolica += valores[i].Eolica;
    }

    for(i = 0; i < n; i++)
    {
        if(max_eolica <= valores[i].Eolica)
        {
            max_eolica = valores[i].Eolica;
            mesmax_eolica = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_eolica >= valores[i].Eolica)
        {
            min_eolica = valores[i].Eolica;
            mesmin_eolica = i+1;
        }
    }

	if(mesmax_eolica <=  12)
    {
    	anomax_eolica = 2021;
	}
	if((mesmax_eolica > 12) && (mesmax_eolica <= 24))
	{
		mesmax_eolica = mesmax_eolica - 12;
		anomax_eolica = 2022;
	}

	if(mesmin_eolica <=  12)
    {
    	anomin_eolica = 2021;
	}
	if((mesmin_eolica > 12) && (mesmin_eolica <= 24))
	{
		mesmin_eolica = mesmin_eolica - 12;
		anomin_eolica = 2022;
	}
/*
    printf("El total producido de eolica en 2 años es: %lf\n", sumatorio_eolica);
    printf("La media mensual producida de eolica en 2 años es: %lf\n", sumatorio_eolica/24);
    printf("La media anual producida de eolica en 2 años es: %lf\n", sumatorio_eolica/2);
    printf("El maximo producido de eolica en 2 años ocurre en %i %i es: %lf\n", mesmax_eolica, anomax_eolica, max_eolica);
    printf("El minimo producido de eolica en 2 años ocurre en %i %i es: %lf\n\n", mesmin_eolica, anomin_eolica, min_eolica);
*/

    double sumatorio_solar_fotovoltaica = 0, max_solar_fotovoltaica = valores[0].Solar_fotovoltaica, min_solar_fotovoltaica = valores[0].Solar_fotovoltaica;
	int mesmax_solar_fotovoltaica = 0, anomax_solar_fotovoltaica = 0, mesmin_solar_fotovoltaica = 0, anomin_solar_fotovoltaica = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_solar_fotovoltaica += valores[i].Solar_fotovoltaica;
    }

    for(i = 0; i < n; i++)
    {
        if(max_solar_fotovoltaica <= valores[i].Solar_fotovoltaica)
        {
            max_solar_fotovoltaica = valores[i].Solar_fotovoltaica;
            mesmax_solar_fotovoltaica = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_solar_fotovoltaica >= valores[i].Solar_fotovoltaica)
        {
            min_solar_fotovoltaica = valores[i].Solar_fotovoltaica;
            mesmin_solar_fotovoltaica = i+1;
        }
    }

	if(mesmax_solar_fotovoltaica <=  12)
    {
    	anomax_solar_fotovoltaica = 2021;
	}
	if((mesmax_solar_fotovoltaica > 12) && (mesmax_solar_fotovoltaica <= 24))
	{
		mesmax_solar_fotovoltaica = mesmax_solar_fotovoltaica - 12;
		anomax_solar_fotovoltaica = 2022;
	}

	if(mesmin_solar_fotovoltaica <=  12)
    {
    	anomin_solar_fotovoltaica = 2021;
	}
	if((mesmin_solar_fotovoltaica > 12) && (mesmin_solar_fotovoltaica <= 24))
	{
		mesmin_solar_fotovoltaica = mesmin_solar_fotovoltaica - 12;
		anomin_solar_fotovoltaica = 2022;
	}
/*
    printf("El total producido de solar_fotovoltaica en 2 años es: %lf\n", sumatorio_solar_fotovoltaica);
    printf("La media mensual producida de solar_fotovoltaica en 2 años es: %lf\n", sumatorio_solar_fotovoltaica/24);
    printf("La media anual producida de solar_fotovoltaica en 2 años es: %lf\n", sumatorio_solar_fotovoltaica/2);
    printf("El maximo producido de solar_fotovoltaica en 2 años ocurre en %i %i es: %lf\n", mesmax_solar_fotovoltaica, anomax_solar_fotovoltaica, max_solar_fotovoltaica);
    printf("El minimo producido de solar_fotovoltaica en 2 años ocurre en %i %i es: %lf\n\n", mesmin_solar_fotovoltaica, anomin_solar_fotovoltaica, min_solar_fotovoltaica);
*/

    double sumatorio_solar_termica = 0, max_solar_termica = valores[0].Solar_termica, min_solar_termica = valores[0].Solar_termica;
	int mesmax_solar_termica = 0, anomax_solar_termica = 0, mesmin_solar_termica = 0, anomin_solar_termica = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_solar_termica += valores[i].Solar_termica;
    }

    for(i = 0; i < n; i++)
    {
        if(max_solar_termica <= valores[i].Solar_termica)
        {
            max_solar_termica = valores[i].Solar_termica;
            mesmax_solar_termica = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_solar_termica >= valores[i].Solar_termica)
        {
            min_solar_termica = valores[i].Solar_termica;
            mesmin_solar_termica = i+1;
        }
    }

	if(mesmax_solar_termica <=  12)
    {
    	anomax_solar_termica = 2021;
	}
	if((mesmax_solar_termica > 12) && (mesmax_solar_termica <= 24))
	{
		mesmax_solar_termica = mesmax_solar_termica - 12;
		anomax_solar_termica = 2022;
	}

	if(mesmin_solar_termica <=  12)
    {
    	anomin_solar_termica = 2021;
	}
	if((mesmin_solar_termica > 12) && (mesmin_solar_termica <= 24))
	{
		mesmin_solar_termica = mesmin_solar_termica - 12;
		anomin_solar_termica = 2022;
	}
/*
    printf("El total producido de solar_termica en 2 años es: %lf\n", sumatorio_solar_termica);
    printf("La media mensual producida de solar_termica en 2 años es: %lf\n", sumatorio_solar_termica/24);
    printf("La media anual producida de solar_termica en 2 años es: %lf\n", sumatorio_solar_termica/2);
    printf("El maximo producido de solar_termica en 2 años ocurre en %i %i es: %lf\n", mesmax_solar_termica, anomax_solar_termica, max_solar_termica);
    printf("El minimo producido de solar_termica en 2 años ocurre en %i %i es: %lf\n\n", mesmin_solar_termica, anomin_solar_termica, min_solar_termica);
*/


    double sumatorio_otras_renovables = 0, max_otras_renovables = valores[0].Otras_renovables, min_otras_renovables = valores[0].Otras_renovables;
	int mesmax_otras_renovables = 0, anomax_otras_renovables = 0, mesmin_otras_renovables = 0, anomin_otras_renovables = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_otras_renovables += valores[i].Otras_renovables;
    }

    for(i = 0; i < n; i++)
    {
        if(max_otras_renovables <= valores[i].Otras_renovables)
        {
            max_otras_renovables = valores[i].Otras_renovables;
            mesmax_otras_renovables = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_otras_renovables >= valores[i].Otras_renovables)
        {
            min_otras_renovables = valores[i].Otras_renovables;
            mesmin_otras_renovables = i+1;
        }
    }

	if(mesmax_otras_renovables <=  12)
    {
    	anomax_otras_renovables = 2021;
	}
	if((mesmax_otras_renovables > 12) && (mesmax_otras_renovables <= 24))
	{
		mesmax_otras_renovables = mesmax_otras_renovables - 12;
		anomax_otras_renovables = 2022;
	}

	if(mesmin_otras_renovables <=  12)
    {
    	anomin_otras_renovables = 2021;
	}
	if((mesmin_otras_renovables > 12) && (mesmin_otras_renovables <= 24))
	{
		mesmin_otras_renovables = mesmin_otras_renovables - 12;
		anomin_otras_renovables = 2022;
	}
/*
    printf("El total producido de otras_renovables en 2 años es: %lf\n", sumatorio_otras_renovables);
    printf("La media mensual producida de otras_renovables en 2 años es: %lf\n", sumatorio_otras_renovables/24);
    printf("La media anual producida de otras_renovables en 2 años es: %lf\n", sumatorio_otras_renovables/2);
    printf("El maximo producido de otras_renovables en 2 años ocurre en %i %i es: %lf\n", mesmax_otras_renovables, anomax_otras_renovables, max_otras_renovables);
    printf("El minimo producido de otras_renovables en 2 años ocurre en %i %i es: %lf\n\n", mesmin_otras_renovables, anomin_otras_renovables, min_otras_renovables);
*/


    double sumatorio_cogeneracion = 0, max_cogeneracion = valores[0].Cogeneracion, min_cogeneracion = valores[0].Cogeneracion;
	int mesmax_cogeneracion = 0, anomax_cogeneracion = 0, mesmin_cogeneracion = 0, anomin_cogeneracion = 0;
    for(i = 0; i < n; i++)
    {
        sumatorio_cogeneracion += valores[i].Cogeneracion;
    }

    for(i = 0; i < n; i++)
    {
        if(max_cogeneracion <= valores[i].Cogeneracion)
        {
            max_cogeneracion = valores[i].Cogeneracion;
            mesmax_cogeneracion = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_cogeneracion >= valores[i].Cogeneracion)
        {
            min_cogeneracion = valores[i].Cogeneracion;
            mesmin_cogeneracion = i+1;
        }
    }

	if(mesmax_cogeneracion <=  12)
    {
    	anomax_cogeneracion = 2021;
	}
	if((mesmax_cogeneracion > 12) && (mesmax_cogeneracion <= 24))
	{
		mesmax_cogeneracion = mesmax_cogeneracion - 12;
		anomax_cogeneracion = 2022;
	}

	if(mesmin_cogeneracion <=  12)
    {
    	anomin_cogeneracion = 2021;
	}
	if((mesmin_cogeneracion > 12) && (mesmin_cogeneracion <= 24))
	{
		mesmin_cogeneracion = mesmin_cogeneracion - 12;
		anomin_cogeneracion = 2022;
	}
/*
    printf("El total producido de cogeneracion en 2 años es: %lf\n", sumatorio_cogeneracion);
    printf("La media mensual producida de cogeneracion en 2 años es: %lf\n", sumatorio_cogeneracion/24);
    printf("La media anual producida de cogeneracion en 2 años es: %lf\n", sumatorio_cogeneracion/2);
    printf("El maximo producido de cogeneracion en 2 años ocurre en %i %i es: %lf\n", mesmax_cogeneracion, anomax_cogeneracion, max_cogeneracion);
    printf("El minimo producido de cogeneracion en 2 años ocurre en %i %i es: %lf\n\n", mesmin_cogeneracion, anomin_cogeneracion, min_cogeneracion);
*/

    double sumatorio_residuos_no_renovables = 0, max_residuos_no_renovables = valores[0].Residuos_no_renovables, min_residuos_no_renovables = valores[0].Residuos_no_renovables;
	int mesmax_residuos_no_renovables = 0, anomax_residuos_no_renovables = 0, mesmin_residuos_no_renovables = 0, anomin_residuos_no_renovables = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_residuos_no_renovables += valores[i].Residuos_no_renovables;
    }

    for(i = 0; i < n; i++)
    {
        if(max_residuos_no_renovables <= valores[i].Residuos_no_renovables)
        {
            max_residuos_no_renovables = valores[i].Residuos_no_renovables;
            mesmax_residuos_no_renovables = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_residuos_no_renovables >= valores[i].Residuos_no_renovables)
        {
            min_residuos_no_renovables = valores[i].Residuos_no_renovables;
            mesmin_residuos_no_renovables = i+1;
        }
    }

	if(mesmax_residuos_no_renovables <=  12)
    {
    	anomax_residuos_no_renovables = 2021;
	}
	if((mesmax_residuos_no_renovables > 12) && (mesmax_residuos_no_renovables <= 24))
	{
		mesmax_residuos_no_renovables = mesmax_residuos_no_renovables - 12;
		anomax_residuos_no_renovables = 2022;
	}

	if(mesmin_residuos_no_renovables <=  12)
    {
    	anomin_residuos_no_renovables = 2021;
	}
	if((mesmin_residuos_no_renovables > 12) && (mesmin_residuos_no_renovables <= 24))
	{
		mesmin_residuos_no_renovables = mesmin_residuos_no_renovables - 12;
		anomin_residuos_no_renovables = 2022;
	}
/*
    printf("El total producido de residuos_no_renovables en 2 años es: %lf\n", sumatorio_residuos_no_renovables);
    printf("La media mensual producida de residuos_no_renovables en 2 años es: %lf\n", sumatorio_residuos_no_renovables/24);
    printf("La media anual producida de residuos_no_renovables en 2 años es: %lf\n", sumatorio_residuos_no_renovables/2);
    printf("El maximo producido de residuos_no_renovables en 2 años ocurre en %i %i es: %lf\n", mesmax_residuos_no_renovables, anomax_residuos_no_renovables, max_residuos_no_renovables);
    printf("El minimo producido de residuos_no_renovables en 2 años ocurre en %i %i es: %lf\n\n", mesmin_residuos_no_renovables, anomin_residuos_no_renovables, min_residuos_no_renovables);
*/

    double sumatorio_residuos_renovables = 0, max_residuos_renovables = valores[0].Residuos_renovables, min_residuos_renovables = valores[0].Residuos_renovables;
	int mesmax_residuos_renovables = 0, anomax_residuos_renovables = 0, mesmin_residuos_renovables = 0, anomin_residuos_renovables = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_residuos_renovables += valores[i].Residuos_renovables;
    }

    for(i = 0; i < n; i++)
    {
        if(max_residuos_renovables <= valores[i].Residuos_renovables)
        {
            max_residuos_renovables = valores[i].Residuos_renovables;
            mesmax_residuos_renovables = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_residuos_renovables >= valores[i].Residuos_renovables)
        {
            min_residuos_renovables = valores[i].Residuos_renovables;
            mesmin_residuos_renovables = i+1;
        }
    }

    if(mesmax_residuos_renovables <=  12)
    {
    	anomax_residuos_renovables = 2021;
	}
	if((mesmax_residuos_renovables > 12) && (mesmax_residuos_renovables <= 24))
	{
		mesmax_residuos_renovables = mesmax_residuos_renovables - 12;
		anomax_residuos_renovables = 2022;
	}

	if(mesmin_residuos_renovables <=  12)
    {
    	anomin_residuos_renovables = 2021;
	}
	if((mesmin_residuos_renovables > 12) && (mesmin_residuos_renovables <= 24))
	{
		mesmin_residuos_renovables = mesmin_residuos_renovables - 12;
		anomin_residuos_renovables = 2022;
	}
/*
    printf("El total producido de residuos_renovables en 2 años es: %lf\n", sumatorio_residuos_renovables);
    printf("La media mensual producida de residuos_renovables en 2 años es: %lf\n", sumatorio_residuos_renovables/24);
    printf("La media anual producida de residuos_renovables en 2 años es: %lf\n", sumatorio_residuos_renovables/2);
    printf("El maximo producido de residuos_renovables en 2 años ocurre en %i %i es: %lf\n", mesmax_residuos_renovables, anomax_residuos_renovables, max_residuos_renovables);
    printf("El minimo producido de residuos_renovables en 2 años ocurre en %i %i es: %lf\n\n", mesmin_residuos_renovables, anomin_residuos_renovables, min_residuos_renovables);
*/

    double sumatorio_generacion_total = 0, max_generacion_total = valores[0].Generacion_total, min_generacion_total = valores[0].Generacion_total;
	int mesmax_generacion_total = 0, anomax_generacion_total = 0, mesmin_generacion_total = 0, anomin_generacion_total = 0;

    for(i = 0; i < n; i++)
    {
        sumatorio_generacion_total += valores[i].Generacion_total;
    }

    for(i = 0; i < n; i++)
    {
        if(max_generacion_total <= valores[i].Generacion_total)
        {
            max_generacion_total = valores[i].Generacion_total;
            mesmax_generacion_total = i+1;

        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_generacion_total >= valores[i].Generacion_total)
        {
            min_generacion_total = valores[i].Generacion_total;
            mesmin_generacion_total = i+1;
        }
    }

	if(mesmax_generacion_total <=  12)
    {
    	anomax_generacion_total = 2021;
	}
	if((mesmax_generacion_total > 12) && (mesmax_generacion_total <= 24))
	{
		mesmax_generacion_total = mesmax_generacion_total - 12;
		anomax_generacion_total = 2022;
	}

	if(mesmin_generacion_total <=  12)
    {
    	anomin_generacion_total = 2021;
	}
	if((mesmin_generacion_total > 12) && (mesmin_generacion_total <= 24))
	{
		mesmin_generacion_total = mesmin_generacion_total - 12;
		anomin_generacion_total = 2022;
	}
/*
    printf("El total producido de generacion_total en 2 años es: %lf\n", sumatorio_generacion_total);
    printf("La media mensual producida de generacion_total en 2 años es: %lf\n", sumatorio_generacion_total/24);
    printf("La media anual producida de generacion_total en 2 años es: %lf\n", sumatorio_generacion_total/2);
    printf("El maximo producido de generacion_total en 2 años ocurre en %i %i es: %lf\n", mesmax_generacion_total, anomax_generacion_total, max_generacion_total);
    printf("El minimo producido de generacion_total en 2 años ocurre en %i %i es: %lf\n\n", mesmin_generacion_total, anomin_generacion_total, min_generacion_total);
*/
	double sumatorio_renovable = 0, renovable[n];
	int mesmax_renovable = 0, anomax_renovable = 0, mesmin_renovable = 0, anomin_renovable = 0;

    for(i = 0; i < n; i++)
    {
        renovable[i] = valores[i].Hidraulica + valores[i].Turbinacion_bombeo + valores[i].Nuclear + valores[i].Hidroeolica + valores[i].Eolica + valores[i].Solar_fotovoltaica + valores[i].Solar_termica + valores[i].Otras_renovables;
    }

    for(i = 0; i < n; i++)
    {
        sumatorio_renovable += renovable[i];
    }

	double max_renovable = renovable[0], min_renovable = renovable[0];

    for(i = 0; i < n; i++)
    {
        if(max_renovable <= renovable[i])
        {
            max_renovable = renovable[i];
            mesmax_renovable = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_renovable >= renovable[i])
        {
            min_renovable = renovable[i];
            mesmin_renovable = i+1;
        }
    }

	if(mesmax_renovable <=  12)
    {
    	anomax_renovable = 2021;
	}
	if((mesmax_renovable > 12) && (mesmax_renovable <= 24))
	{
		mesmax_renovable = mesmax_renovable - 12;
		anomax_renovable = 2022;
	}

	if(mesmin_renovable <=  12)
    {
    	anomin_renovable = 2021;
	}
	if((mesmin_renovable > 12) && (mesmin_renovable <= 24))
	{
		mesmin_renovable = mesmin_renovable - 12;
		anomin_renovable = 2022;
	}
/*
    printf("El total producido de renovable en 2 años es: %lf\n", sumatorio_renovable);
    printf("La media mensual producida de renovable en 2 años es: %lf\n", sumatorio_renovable/24);
    printf("La media anual producida de renovable en 2 años es: %lf\n", sumatorio_renovable/2);
    printf("El maximo producido de renovable en 2 años ocurre en %i %i es: %lf\n", mesmax_renovable, anomax_renovable, max_renovable);
    printf("El minimo producido de renovable en 2 años ocurre en %i %i es: %lf\n\n", mesmin_renovable, anomin_renovable, min_renovable);
*/

	double sumatorio_no_renovable = 0, no_renovable[n];
	int mesmax_no_renovable = 0, anomax_no_renovable = 0, mesmin_no_renovable = 0, anomin_no_renovable = 0;

    for(i = 0; i < n; i++)
    {
        no_renovable[i] = valores[i].Carbon + valores[i].Fuel_gas + valores[i].Motores_diesel;
    }

    for(i = 0; i < n; i++)
    {
        sumatorio_no_renovable += no_renovable[i];
    }

	double max_no_renovable = no_renovable[0], min_no_renovable = renovable[0];

    for(i = 0; i < n; i++)
    {
        if(max_no_renovable <= no_renovable[i])
        {
            max_no_renovable = no_renovable[i];
            mesmax_no_renovable = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_no_renovable >= no_renovable[i])
        {
            min_no_renovable = no_renovable[i];
            mesmin_no_renovable = i+1;
        }
    }

	if(mesmax_no_renovable <=  12)
    {
    	anomax_no_renovable = 2021;
	}
	if((mesmax_no_renovable > 12) && (mesmax_no_renovable <= 24))
	{
		mesmax_no_renovable = mesmax_no_renovable - 12;
		anomax_no_renovable = 2022;
	}

	if(mesmin_no_renovable <=  12)
    {
    	anomin_no_renovable = 2021;
	}
	if((mesmin_no_renovable > 12) && (mesmin_no_renovable <= 24))
	{
		mesmin_no_renovable = mesmin_no_renovable - 12;
		anomin_no_renovable = 2022;
	}
/*
    printf("El total producido de no_renovable en 2 años es: %lf\n", sumatorio_no_renovable);
    printf("La media mensual producida de no_renovable en 2 años es: %lf\n", sumatorio_no_renovable/24);
    printf("La media anual producida de no_renovable en 2 años es: %lf\n", sumatorio_no_renovable/2);
    printf("El maximo producido de no_renovable en 2 años ocurre en %i %i es: %lf\n", mesmax_no_renovable, anomax_no_renovable, max_no_renovable);
    printf("El minimo producido de no_renovable en 2 años ocurre en %i %i es: %lf\n\n", mesmin_no_renovable, anomin_no_renovable, min_no_renovable);
*/

	double sumatorio_mezcla = 0, mezcla[n];
	int mesmax_mezcla = 0, anomax_mezcla = 0, mesmin_mezcla = 0, anomin_mezcla = 0;

    for(i = 0; i < n; i++)
    {
        mezcla[i] = valores[i].Turbina_gas + valores[i].Turbina_vapor + valores[i].Ciclo_combinado + valores[i].Cogeneracion;
    }

    for(i = 0; i < n; i++)
    {
        sumatorio_mezcla += mezcla[i];
    }

	double max_mezcla = mezcla[0], min_mezcla = mezcla[0];

    for(i = 0; i < n; i++)
    {
        if(max_mezcla <= mezcla[i])
        {
            max_mezcla = mezcla[i];
            mesmax_mezcla = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_mezcla >= mezcla[i])
        {
            min_mezcla = mezcla[i];
            mesmin_mezcla = i+1;

        }
    }

	if(mesmax_mezcla <=  12)
    {
    	anomax_mezcla = 2021;
	}
	if((mesmax_mezcla > 12) && (mesmax_mezcla <= 24))
	{
		mesmax_mezcla = mesmax_mezcla - 12;
		anomax_mezcla = 2022;
	}

	if(mesmin_mezcla <=  12)
    {
    	anomin_mezcla = 2021;
	}
	if((mesmin_mezcla > 12) && (mesmin_mezcla <= 24))
	{
		mesmin_mezcla = mesmin_mezcla - 12;
		anomin_mezcla = 2022;
	}
/*
    printf("El total producido de mezcla en 2 años es: %lf\n", sumatorio_mezcla);
    printf("La media mensual producida de mezcla en 2 años es: %lf\n", sumatorio_mezcla/24);
    printf("La media anual producida de mezcla en 2 años es: %lf\n", sumatorio_mezcla/2);
    printf("El maximo producido de mezcla en 2 años ocurre en %i %i es: %lf\n", mesmax_mezcla, anomax_mezcla, max_mezcla);
    printf("El minimo producido de mezcla en 2 años ocurre en %i %i es: %lf\n\n", mesmin_mezcla, anomin_mezcla, min_mezcla);
*/



	double sumatorio_residuos = 0, residuos[n];
	int mesmax_residuos = 0, anomax_residuos = 0, mesmin_residuos = 0, anomin_residuos = 0;

    for(i = 0; i < n; i++)
    {
        residuos[i] = valores[i].Residuos_no_renovables + valores[i].Residuos_renovables;
    }

    for(i = 0; i < n; i++)
    {
        sumatorio_residuos += residuos[i];
    }

	double max_residuos = residuos[0], min_residuos = residuos[0];

    for(i = 0; i < n; i++)
    {
        if(max_residuos <= residuos[i])
        {
            max_residuos = residuos[i];
            mesmax_residuos = i+1;
        }
    }

    for(i = 0; i < n; i++)
    {
        if(min_residuos >= residuos[i])
        {
            min_residuos = residuos[i];
            mesmin_residuos = i+1;

        }
    }

	if(mesmax_residuos <=  12)
    {
    	anomax_residuos = 2021;
	}
	if((mesmax_residuos > 12) && (mesmax_residuos <= 24))
	{
		mesmax_residuos = mesmax_residuos - 12;
		anomax_residuos = 2022;
	}

	if(mesmin_residuos <=  12)
    {
    	anomin_residuos = 2021;
	}
	if((mesmin_residuos > 12) && (mesmin_residuos <= 24))
	{
		mesmin_residuos = mesmin_residuos - 12;
		anomin_residuos = 2022;
	}
/*
    printf("El total producido de residuos en 2 años es: %lf\n", sumatorio_residuos);
    printf("La media mensual producida de residuos en 2 años es: %lf\n", sumatorio_residuos/24);
    printf("La media anual producida de residuos en 2 años es: %lf\n", sumatorio_residuos/2);
    printf("El maximo producido de residuos en 2 años ocurre en %i %i es: %lf\n", mesmax_residuos, anomax_residuos, max_residuos);
    printf("El minimo producido de residuos en 2 años ocurre en %i %i es: %lf\n\n", mesmin_residuos, anomin_residuos, min_residuos);
*/

 do
    {
        printf("\nElige sobre que energia realizar los calculos\n");

        printf("1-Hidraulica\t\t     2-Turbinacion bombeo\n");

        printf("3-Nuclear\t\t     4-Carbon\n");

        printf("5-Fuel gas\t\t     6-Motores diesel\n");

        printf("7-Turbina gas\t\t     8-Turbina vapor\n");

        printf("9-Ciclo combinado\t     10-Hidroeolica\n");

        printf("11-Eolica\t\t     12-Solar fotovoltaica\n");

        printf("13-Solar termica\t     14-Otras renovables\n");

        printf("15-Cogeneracion\t\t     16-Residuos no renovables\n");

        printf("17-Residuos renovables\t     18-Energias renovables\n");

        printf("19-Energia no renovables     20-Mezcla\n");

        printf("21-Residuos\t\t     22-Generacion total\n");

        printf("23-Salir\n\n");

        scanf("%i", &chose);

        printf("\n");

		system("cls");

        switch(chose)
        {
            case 1:
                 printf("El total producido de hidraulica en 2 años es: %lf GWh\n", sumatorio_hidraulica);
   				 printf("La media mensual producida de hidraulica en 2 años es: %lf GWh\n", sumatorio_hidraulica/24);
 				 printf("La media anual producida de hidraulica en 2 años es: %lf GWh\n", sumatorio_hidraulica/2);
  				 printf("El maximo producido de hidraulica en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_hidraulica, anomax_hidraulica, max_hidraulica);
				 printf("El minimo producido de hidraulica en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_hidraulica, anomin_hidraulica, min_hidraulica);
                break;

            case 2:
                printf("El total producido de turbinacion bombeo en 2 años es: %lf GWh\n", sumatorio_turbinacion_bombeo);
  				printf("La media mensual producida de turbinacion bombeo en 2 años es: %lf GWh\n", sumatorio_turbinacion_bombeo/24);
   				printf("La media anual producida de turbinacion bombeo en 2 años es: %lf GWh\n", sumatorio_turbinacion_bombeo/2);
  			    printf("El maximo producido de turbinacion bombeo en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_turbinacion_bombeo, anomax_turbinacion_bombeo, max_turbinacion_bombeo);
    			printf("El minimo producido de turbinacion bombeo en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_turbinacion_bombeo, anomin_turbinacion_bombeo, min_turbinacion_bombeo);
	            break;

            case 3:
                printf("El total producido de nuclear en 2 años es: %lf GWh\n", sumatorio_nuclear);
   			    printf("La media mensual producida de nuclear en 2 años es: %lf GWh\n", sumatorio_nuclear/24);
   			    printf("La media anual producida de nuclear en 2 años es: %lf GWh\n", sumatorio_nuclear/2);
   			    printf("El maximo producido de nuclear en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_nuclear, anomax_nuclear, max_nuclear);
  			    printf("El minimo producido de nuclear en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_nuclear, anomin_nuclear, min_nuclear);
                break;
            case 4:
                printf("El total producido de carbon en 2 años es: %lf GWh\n", sumatorio_carbon);
  			    printf("La media mensual producida de carbon en 2 años es: %lf GWh\n", sumatorio_carbon/24);
  			    printf("La media anual producida de carbon en 2 años es: %lf GWh\n", sumatorio_carbon/2);
  			    printf("El maximo producido de carbon en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_carbon, anomax_carbon, max_carbon);
 			    printf("El minimo producido de carbon en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_carbon, anomin_carbon, min_carbon);
                break;

            case 5:
                printf("El total producido de fuel Gas en 2 años es: %lf GWh\n", sumatorio_fuel_Gas);
    			printf("La media mensual producida de fuel Gas en 2 años es: %lf GWh\n", sumatorio_fuel_Gas/24);
  			 	printf("La media anual producida de fuel Gas en 2 años es: %lf GWh\n", sumatorio_fuel_Gas/2);
    			printf("El maximo producido de fuel Gas en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_fuel_Gas, anomax_fuel_Gas, max_fuel_Gas);
    			printf("El minimo producido de fuel Gas en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_fuel_Gas, anomin_fuel_Gas, min_fuel_Gas);
                break;

            case 6:
                printf("El total producido de motores diesel en 2 años es: %lf GWh\n", sumatorio_motores_diesel);
    			printf("La media mensual producida de motores diesel en 2 años es: %lf GWh\n", sumatorio_motores_diesel/24);
    			printf("La media anual producida de motores diesel en 2 años es: %lf GWh\n", sumatorio_motores_diesel/2);
    			printf("El maximo producido de motores diesel en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_motores_diesel, anomax_motores_diesel, max_motores_diesel);
    			printf("El minimo producido de motores diesel en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_motores_diesel, anomin_motores_diesel, min_motores_diesel);
                break;

            case 7:
                printf("El total producido de turbina de gas en 2 años es: %lf GWh\n", sumatorio_turbina_de_gas);
    			printf("La media mensual producida de turbina de gas en 2 años es: %lf GWh\n", sumatorio_turbina_de_gas/24);
    			printf("La media anual producida de turbina de gas en 2 años es: %lf GWh\n", sumatorio_turbina_de_gas/2);
    			printf("El maximo producido de turbina de gas en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_turbina_de_gas, anomax_turbina_de_gas, max_turbina_de_gas);
    			printf("El minimo producido de turbina de gas en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_turbina_de_gas, anomin_turbina_de_gas, min_turbina_de_gas);
                break;

            case 8:
                printf("El total producido de turbina de vapor en 2 años es: %lf GWh\n", sumatorio_turbina_de_vapor);
    			printf("La media mensual producida de turbina de vapor en 2 años es: %lf GWh\n", sumatorio_turbina_de_vapor/24);
    			printf("La media anual producida de turbina de vapor en 2 años es: %lf GWh\n", sumatorio_turbina_de_vapor/2);
    			printf("El maximo producido de turbina de vapor en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_turbina_de_vapor, anomax_turbina_de_vapor, max_turbina_de_vapor);
    			printf("El minimo producido de turbina de vapor en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_turbina_de_vapor, anomin_turbina_de_vapor, min_turbina_de_vapor);
                break;

            case 9:
                printf("El total producido de ciclo combinado en 2 años es: %lf GWh\n", sumatorio_ciclo_combinado);
    			printf("La media mensual producida de ciclo combinado en 2 años es: %lf GWh\n", sumatorio_ciclo_combinado/24);
    			printf("La media anual producida de ciclo combinado en 2 años es: %lf GWh\n", sumatorio_ciclo_combinado/2);
    			printf("El maximo producido de ciclo combinado en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_ciclo_combinado, anomax_ciclo_combinado, max_ciclo_combinado);
    			printf("El minimo producido de ciclo combinado en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_ciclo_combinado, anomin_ciclo_combinado, min_ciclo_combinado);
                break;

            case 10:
                printf("El total producido de hidroeolica en 2 años es: %lf GWh\n", sumatorio_hidroeolica);
    			printf("La media mensual producida de hidroeolica en 2 años es: %lf GWh\n", sumatorio_hidroeolica/24);
    			printf("La media anual producida de hidroeolica en 2 años es: %lf GWh\n", sumatorio_hidroeolica/2);
    			printf("El maximo producido de hidroeolica en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_hidroeolica, anomax_hidroeolica, max_hidroeolica);
    			printf("El minimo producido de hidroeolica en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_hidroeolica, anomin_hidroeolica, min_hidroeolica);
                break;

            case 11:
                printf("El total producido de eolica en 2 años es: %lf GWh\n", sumatorio_eolica);
    			printf("La media mensual producida de eolica en 2 años es: %lf GWh\n", sumatorio_eolica/24);
    			printf("La media anual producida de eolica en 2 años es: %lf GWh\n", sumatorio_eolica/2);
    			printf("El maximo producido de eolica en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_eolica, anomax_eolica, max_eolica);
    			printf("El minimo producido de eolica en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_eolica, anomin_eolica, min_eolica);
                break;

            case 12:
                printf("El total producido de solar fotovoltaica en 2 años es: %lf GWh\n", sumatorio_solar_fotovoltaica);
    			printf("La media mensual producida de solar fotovoltaica en 2 años es: %lf GWh\n", sumatorio_solar_fotovoltaica/24);
    			printf("La media anual producida de solar fotovoltaica en 2 años es: %lf GWh\n", sumatorio_solar_fotovoltaica/2);
   				printf("El maximo producido de solar fotovoltaica en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_solar_fotovoltaica, anomax_solar_fotovoltaica, max_solar_fotovoltaica);
    			printf("El minimo producido de solar fotovoltaica en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_solar_fotovoltaica, anomin_solar_fotovoltaica, min_solar_fotovoltaica);
                break;

            case 13:
                printf("El total producido de solar termica en 2 años es: %lf\n", sumatorio_solar_termica);
    			printf("La media mensual producida de solar termica en 2 años es: %lf\n", sumatorio_solar_termica/24);
    			printf("La media anual producida de solar termica en 2 años es: %lf\n", sumatorio_solar_termica/2);
    			printf("El maximo producido de solar termica en 2 años ocurre el mes %i de %i con: %lf\n", mesmax_solar_termica, anomax_solar_termica, max_solar_termica);
    			printf("El minimo producido de solar termica en 2 años ocurre el mes %i de %i con: %lf\n\n", mesmin_solar_termica, anomin_solar_termica, min_solar_termica);
                break;

            case 14:
                printf("El total producido de otras renovables en 2 años es: %lf GWh\n", sumatorio_otras_renovables);
    			printf("La media mensual producida de otras renovables en 2 años es: %lf GWh\n", sumatorio_otras_renovables/24);
    			printf("La media anual producida de otras renovables en 2 años es: %lf GWh\n", sumatorio_otras_renovables/2);
    			printf("El maximo producido de otras renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_otras_renovables, anomax_otras_renovables, max_otras_renovables);
    			printf("El minimo producido de otras renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_otras_renovables, anomin_otras_renovables, min_otras_renovables);
                break;

            case 15:
                printf("El total producido de cogeneracion en 2 años es: %lf GWh\n", sumatorio_cogeneracion);
    			printf("La media mensual producida de cogeneracion en 2 años es: %lf GWh\n", sumatorio_cogeneracion/24);
    			printf("La media anual producida de cogeneracion en 2 años es: %lf GWh\n", sumatorio_cogeneracion/2);
    			printf("El maximo producido de cogeneracion en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_cogeneracion, anomax_cogeneracion, max_cogeneracion);
    			printf("El minimo producido de cogeneracion en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_cogeneracion, anomin_cogeneracion, min_cogeneracion);
                break;

            case 16:
                printf("El total producido de residuos no renovables en 2 años es: %lf GWh\n", sumatorio_residuos_no_renovables);
    			printf("La media mensual producida de residuos no renovables en 2 años es: %lf GWh\n", sumatorio_residuos_no_renovables/24);
    			printf("La media anual producida de residuos no renovables en 2 años es: %lf GWh\n", sumatorio_residuos_no_renovables/2);
    			printf("El maximo producido de residuos no renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_residuos_no_renovables, anomax_residuos_no_renovables, max_residuos_no_renovables);
    			printf("El minimo producido de residuos no renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_residuos_no_renovables, anomin_residuos_no_renovables, min_residuos_no_renovables);
                break;

            case 17:
                printf("El total producido de residuos renovables en 2 años es: %lf GWh\n", sumatorio_residuos_renovables);
    			printf("La media mensual producida de residuos renovables en 2 años es: %lf GWh\n", sumatorio_residuos_renovables/24);
    			printf("La media anual producida de residuos renovables en 2 años es: %lf GWh\n", sumatorio_residuos_renovables/2);
    			printf("El maximo producido de residuos renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_residuos_renovables, anomax_residuos_renovables, max_residuos_renovables);
    			printf("El minimo producido de residuos renovables en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_residuos_renovables, anomin_residuos_renovables, min_residuos_renovables);
                break;


            case 18:
                printf("El total producido de renovable en 2 años es: %lf GWh\n", sumatorio_renovable);
    			printf("La media mensual producida de renovable en 2 años es: %lf GWh\n", sumatorio_renovable/24);
    			printf("La media anual producida de renovable en 2 años es: %lf GWh\n", sumatorio_renovable/2);
    			printf("El maximo producido de renovable en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_renovable, anomax_renovable, max_renovable);
   				printf("El minimo producido de renovable en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_renovable, anomin_renovable, min_renovable);
                break;

			case 19:
                printf("El total producido de no renovable en 2 años es: %lf GWh\n", sumatorio_no_renovable);
    			printf("La media mensual producida de no renovable en 2 años es: %lf GWh\n", sumatorio_no_renovable/24);
    			printf("La media anual producida de no renovable en 2 años es: %lf GWh\n", sumatorio_no_renovable/2);
    			printf("El maximo producido de no renovable en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_no_renovable, anomax_no_renovable, max_no_renovable);
    			printf("El minimo producido de no renovable en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_no_renovable, anomin_no_renovable, min_no_renovable);
                break;

            case 20:
                printf("El total producido de mezcla en 2 años es: %lf GWh\n", sumatorio_mezcla);
    			printf("La media mensual producida de mezcla en 2 años es: %lf GWh\n", sumatorio_mezcla/24);
    			printf("La media anual producida de mezcla en 2 años es: %lf GWh\n", sumatorio_mezcla/2);
    			printf("El maximo producido de mezcla en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_mezcla, anomax_mezcla, max_mezcla);
    			printf("El minimo producido de mezcla en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_mezcla, anomin_mezcla, min_mezcla);
                break;

            case 21:
                printf("El total producido de residuos en 2 años es: %lf GWh\n", sumatorio_residuos);
    			printf("La media mensual producida de residuos en 2 años es: %lf GWh\n", sumatorio_residuos/24);
    			printf("La media anual producida de residuos en 2 años es: %lf GWh\n", sumatorio_residuos/2);
    			printf("El maximo producido de residuos en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_residuos, anomax_residuos, max_residuos);
    			printf("El minimo producido de residuos en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_residuos, anomin_residuos, min_residuos);
                break;

            case 22:
                printf("El total producido de Generacion total en 2 años es: %lf GWh\n", sumatorio_generacion_total);
                printf("La media mensual producida de Generacion total en 2 años es: %lf GWh\n", sumatorio_generacion_total/24);
                printf("La media anual producida de Generacion total en 2 años es: %lf GWh\n", sumatorio_generacion_total/2);
                printf("El maximo producido de residuos en 2 años ocurre el mes %i de %i con: %lf GWh\n", mesmax_generacion_total, anomax_generacion_total, max_generacion_total);
    			printf("El minimo producido de residuos en 2 años ocurre el mes %i de %i con: %lf GWh\n\n", mesmin_generacion_total, anomin_generacion_total, min_generacion_total);
                break;

            case 23:
                printf("Saliendo\n");
                break;

            default:
                printf("Opcion no disponible\n");
                break;
        }
    }
    while(chose != 23);
}
	
 

}

 

int crear_nuevo_fichero()
{

 

}

 

void diversos_calculos()
{

 

}
