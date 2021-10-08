/*
 ============================================================================
 Name        : PetreFedericoJulian_PP.c
 Author      : Federico Petre
 Version     :
 Copyright   : Y
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "perro.h"
#include "funcionesInputs.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion = -1;

	printf("Bienvenido a la guardería de perros\n");

	while(opcion != 7)
	{
		 funcionesInputs_pedirYValidarEntero("Elija una opcion (1-7):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- SALIR\n", "Error, elija una opcion (1-7):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- SALIR\n", 1, 7, &opcion);

		 switch(opcion)
		 {
			 case 1:
				 printf("Ha elejido la opcion 1- RESERVAR ESTADIA\n");

				 break;
			 case 2:
				 printf("Ha elejido la opcion 2- MODIFICAR ESTADIA\n");

				 break;
			 case 3:
				 printf("Ha elejido la opcion 3- CANCELAR ESTADIA\n");

				 break;
			 case 4:
				 printf("Ha elejido la opcion 4- LISTAR ESTADIAS\n");

				 break;
			 case 5:
				 printf("Ha elejido la opcion 5- LISTAR PERROS\n");

				 break;
			 case 6:
				 printf("Ha elejido la opcion 6- Promedio de edad de los perros\n");

				 break;
			 case 7:
				 printf("Ha elejido la opcion 7- SALIR\nSaliendo del sistema....\nHas salido del sistema");
				 break;
		 }

		 if(opcion != 7)
		 {
			 system("pause");
		 }

	}





	return EXIT_SUCCESS;
}
