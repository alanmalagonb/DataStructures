#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"
#include"C:\Users\Alan\Desktop\AyEdd\Arreglos\arreglosc.h"
void cifrador(Elem pal[], Elem key[], int n){
    int i,j;
    Circular r=nuevaC();

    for(i='A';i<='Z';i++) // i='0';i<='9';i++)
       r=formarC(r,i);

    for(i=0;i<n;i++){
       while(primeroC(r)!=pal[i])
            r=rotar(r);

       for(j=0;j<=key[i]-65;j++) // -48
          r=rotar(r);
       pal[i]=primeroC(r);
   }
};

void descifrador(Elem pal[], Elem key[], int n){
    int i,j;
    Circular r=nuevaC();

    for(i='A';i<='Z';i++)
       r=formarC(r,i);

    for(i=0;i<n;i++){
       while(primeroC(r)!=pal[i])
            r=rotar(r);

       for(j=0;j<90-key[i];j++) //25-key[i]
          r=rotar(r);
       pal[i]=primeroC(r);
   }
};

int main(){
    Elem i, j=0, n;
    Circular c=nuevaC();
    Elem pal[80], key[80];

    printf("Texto plano?");
    n=LeeArrElemsN(pal);
    printf("Llave?");
    n=LeeArrElemsN(key);
    printf("Texto plano = %s, llave = %s.\n",pal,key);
    cifrador(pal,key,n);
    printf("Texto cifrado = %s.\n",pal);
    descifrador(pal,key,n);
    printf("Texto plano = %s.\n",pal);

    return 0;
}

/*
    1.- Obtener la palabra pal a cifrar. OK!!!
    2.- Obtener la llave k (de la misma longitud que pal) OK!!!
    3.- Mediante rotaciones cifrar cada letra de pal con
        cada letra de k, es decir p[i] + k[i] mod 26 = x[i]
    4.- Para decifrar calculamos x[i]+(26-k[i]) mod 26 = p[i]
*/
