//////////////// Programa principal (menu)





#include <stdio.h>
#include <string.h>
#include <locale.h> 
#include "libreria de funciones.h"


int main()
{
    setlocale (LC_CTYPE,"spanish");
	
    int opciones, info, seleccion;

    datos valores[25];

    printf("IMPORTANTE: Para que el programa funcione correctamente debe existir en tu equipo\n un fichero con el nombre generacion_por_tecnologias_21_22\n\n");

    do
    {
        menu_principal(&opciones);  //llamada a la funcion menu principal

        switch(opciones)
        {
            case 1:
                informacion(&info);
                break;

            case 2:
                if(apertura_lectura_guardardatos(valores, 25) != 0)
                {
                    return 0;
                }
                else
                {
                    menu_secundario(&seleccion, valores);
                }
                break;

            case 3:
                printf("\nPrograma finalizado\n");
                break;

            default:
                printf("Opcion incorrecta\n\n");
				break;
        }
    }
    while(opciones != 3);


return 0;
}
