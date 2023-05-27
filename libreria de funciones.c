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

 

}

 

int crear_nuevo_fichero()
{

 

}

 

void diversos_calculos()
{

 

}
