#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"

void cifrar(Elem*,Circular,Circular);
void descifrar(Elem*,Circular,Circular);

int main(){
    
    Elem c[200];
    printf("Inserta la palabra:\n");
    fgets(c,200, stdin);
    printf("La palabra es: %s\n",c);

    Elem k[6];
    printf("Inserta la llave:\n");
    fgets(k,6, stdin);
    printf("La llave es: %s\n",k);

    Elem i;
    Circular a=nuevaC();
    for(i='a';i<='z';i++) a=formarC(a,i);
    for(i='A';i<='Z';i++) a=formarC(a,i);


    Circular key=nuevaC();
    int kc;
    for(kc=0;kc<5;kc++) key=formarC(key,k[kc]);
    
    cifrar(c,a,key);
    printf("La palabra cifrada es: %s\n",c);
    
    descifrar(c,a,key);
    printf("La palabra descifrada es: %s\n",c);

    return 0;
}

void cifrar(Elem* c, Circular a, Circular key){
    int j,k;
    for(j=0;j<strlen(c);j++){
        if(isspace(c[j])) continue;
        else{
            while(!EsIgual(c[j],primeroC(a))) a=rotar(a);
            int l = primeroC(key) - '0';
            for(k=0;k<l;k++) a=rotar(a);
            key=rotar(key);
            c[j] = primeroC(a);
        }
    } 
}

void descifrar(Elem* c, Circular a, Circular key){
    int j,k;
    for(j=0;j<strlen(c);j++){
        if(isspace(c[j])) continue;
        else{
            while(!EsIgual(c[j],primeroC(a))) a=rotar(a);
            int l = primeroC(key) - '0';
            for(k=0;k<52-l;k++) a=rotar(a);
            key=rotar(key);
            c[j] = primeroC(a);
        }
    }
}