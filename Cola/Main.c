#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ElemCola.h"
#include"Cola.h"
//E2Malagon2021630433

//Devuelve cola con 10 numeros aleatorios
Cola aleatorios(Cola q){
    int i;
    int n;
    for(i=0;i<10;i++){
        formar(q,rand()%101);
        
    }
    return q;
}

int numerosPares(Cola q){
    //FormaRecursiva

    if(esnueva(q)) return 0;
    else if((primero(q)%2)==0){
        ImpElem(primero(q));
        return 1+numerosPares(q = desformar(q));
    } 
    else{
        ImpElem(primero(q));
        return numerosPares(q = desformar(q));
    } 
    
    //Forma iterativa
    /*int i,n=0;
    for(i=0;i<10;i++){
        ImpElem(primero(q));
        if((primero(q)%2)==0) n++;
        q = desformar(q);
    }*/
    //return n;
}

int main(){
    srand(time(NULL));
    Cola q = nueva();
    q = aleatorios(q);
    printf("Hay %d numeros pares en la cola.",numerosPares(q));
    return 0;
}