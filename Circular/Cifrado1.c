#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"

void cifrar(Elem*,Circular,int);
void descifrar(Elem*,Circular,int);

int main(){
    
    Elem c[200];
    printf("Inserta la palabra:\n");
    scanf("%[^\n]s",&c);
    printf("La palabra es: %s\n",c);

    int p;
    printf("Inserta la llave:\n");
    scanf("%d",&p);

    Elem i;
    Circular a=nuevaC();
    for(i='a';i<='z';i++) a=formarC(a,i);
    for(i='A';i<='Z';i++) a=formarC(a,i);

    cifrar(c,a,p);
    printf("La palabra cifrada es: %s\n",c);
    
    descifrar(c,a,p);
    printf("La palabra descifrada es: %s\n",c);

    return 0;
}

void cifrar(Elem* c, Circular a,int p){
    int j,k;
    for(j=0;j<strlen(c);j++){
        if(isspace(c[j])) continue;
        else{
            while(!EsIgual(c[j],primeroC(a))) a=rotar(a);
            for(k=0;k<p;k++) a=rotar(a);
            c[j] = primeroC(a);
        }
    } 
}

void descifrar(Elem* c, Circular a,int p){
    int j,k;
    for(j=0;j<strlen(c);j++){
        if(isspace(c[j])) continue;
        else{
            while(!EsIgual(c[j],primeroC(a))) a=rotar(a);
            for(k=0;k<(52-p);k++) a=rotar(a);
            c[j] = primeroC(a);
        }
    }
}
