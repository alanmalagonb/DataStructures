#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemTHII.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\ListaTH.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\TablaH.h"


int main(int argc, char *argv[]){
	FILE *ent=fopen(*++argv,"r");
	int Opcion, n=5, i;
	char nompais[80];
	Elem paises[10];
	Elem e;
	TablaH  t=consTH(n);
	
	// Llenado de la tabla.
	fflush(stdin);
	for(i=1;i<=7;i++){
       e=LeeElem(ent);
       t=InsElem(e, t, n);
    }
    
	do{
		printf("\n\tBIENVENIDO A LA TABLA DE PAISES.\n");
		puts("Menu: ");
		puts("0. Salir");
		puts("1. Ver tabla.");
		puts("2. Agregar elemento.");
		puts("3. Eliminar elemento.");
		puts("4. Consultar elemento.");
		puts("5. Limpiar pantalla.");
		printf("Ingrese una opcion: ");
		scanf("%d", &Opcion);
			
		switch(Opcion){
			case 1:
				puts("\n\t1. Ver tabla.");
				puts("Pais - Capital - Gentilicio - Idioma - Divisa - Poblacion - Ingreso \n");
				ImpTablaH(t, n);
				break;
				
			case 2:
				puts("\n\t2. Agregar elemento.");
				puts("Formato: Pais Capital Gentilicio Idioma Divisa Poblacion Ingreso.");
				printf("Escriba el elemento: ");
				e=LeeElemCons();
				t=InsElem(e, t, n);
				break;
				
			case 3:
				puts("\n\t3. Eliminar elemento.");
				printf("Escriba el elemento: ");
				scanf("%s",nompais);
				strcpy(e.pais, nompais);
				Borra(e, t, n);
				break;
			
			case 4: 
				puts("\n\t4. Consultar elemento.");
				printf("Escriba el elemento: ");
				scanf("%s",nompais);
				strcpy(e.pais, nompais);
				Consulta(e, t, n);
				break; 
				
			case 5: 
				system("cls");
				break; 
		}
	}while(Opcion!=0);
}

