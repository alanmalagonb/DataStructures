#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\Elem.h"
#include"C:\Users\Alan\Desktop\AyEdd\Arreglos\Arreglos.h"
#include"C:\Users\Alan\Desktop\AyEdd\Ordenamiento\Ordenamiento.h"

int main(){
    Elem a[50];
    int n;
    puts("Cuantos elementos quieres meter al arreglo?");
    scanf("%d",&n);
    LeeArreglo(a,n);

    //printf("El arreglo es: z s w r d\n");
    //ImpArreglo(a,n);
    insercion(a,n);
    //burbuja(a,n);
    puts("\nEl arreglo ordenado es:\n");
    ImpArreglo(a,n);

    return 0;
}