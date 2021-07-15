#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\Clase\ElemTH.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\Clase\ListaTH.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\Clase\TablaH.h"

int main(int argc, char *argv[]){

    Elem paises[10];
    FILE *ent=fopen(*++argv,"r");
 //   FILE *sal=fopen(*++argv,"w");
    int n=10;//223
    TablaH  t=consTH(n);
    Elem e;
    char nompais[80];
    int i;

    for(i=1;i<=10;i++){
       e=LeeElem(ent);
       t=InsElem(e, t, n);
    }

    menu(e,t,n);

 //   puts("Lista de paises:");
   // ImpTablaH(t,7);

 //   printf("La llave de %s es %d\n",paises[0].pais,Llave(paises[0]));
   /* printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);

    printf("Cual pais quieres eliminar?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Borra(e,t,n);

    printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);

 //   InsElem(TablaH t, int n, Elem e)

    printf("Cual pais quieres agregar?");
    e=LeeElemCons();
    t=InsElem(e, t, n);
    //t[Llave(e)%n]=cons(e,t[Llave(e)%n]);

    printf("Cual pais quieres conocer?");
    scanf("%s",nompais);
    strcpy(e.pais,nompais);
    printf("Llave de %s es %d, y su posicion en la table es %d\n",e.pais,Llave(e),Llave(e)%n);
    Consulta(e,t,n);
*/

    return 0;


}

void menu(Elem e,TablaH t,int n){
   char ch;
   char nompais[80];  
   do{
      printMenu();
      int choice=0;
      scanf("%d", &choice);
      switch(choice){
         case 1: 
            puts("+------+---------+------------+--------+--------+-----------+---------+");
				puts("| Pais | Capital | Gentilicio | Idioma | Divisa | Poblacion | Ingreso |");
				puts("+------+---------+------------+--------+--------+-----------+---------+");
				ImpTablaH(t, n);
            fflush(stdin); 
            break;
         case 2:
				puts("+------+---------+------------+--------+--------+-----------+---------+");
				puts("| Pais | Capital | Gentilicio | Idioma | Divisa | Poblacion | Ingreso |");
            puts("| char | char    | char       | char   | char   | int       | float   |");
				puts("+------+---------+------------+--------+--------+-----------+---------+");
				printf("Ingrese el elemento en orden: \n");
				e=LeeElemCons();
				t=InsElem(e, t, n);
				break;
         case 3:
            printf("Ingrese el pais a eliminar: ");
				scanf("%s",nompais);
				strcpy(e.pais, nompais);
				Borra(e, t, n);
				break;
         case 4:
            printf("Ingrese el pais a consultar: ");
				scanf("%s",nompais);
				strcpy(e.pais, nompais);
				Consulta(e, t, n);
				break; 
      }

      printf("Quieres continuar? (S/N):");  
      fflush(stdin); 
      scanf("%c", &ch);
      system("cls");
   }while(tolower(ch) == 's');
}

void printMenu(){
   printf("Tabla Hash Paises.\n");
	puts("1. Ver tabla.");
	puts("2. Agregar pais.");
	puts("3. Eliminar pais.");
	puts("4. Consultar pais.");
	printf("Escribe una opcion: ");
}