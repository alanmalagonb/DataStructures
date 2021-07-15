#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc2.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"
#include"C:\Users\Alan\Desktop\AyEdd\Lista\Lista.h"

int random(int,int);
Circular printQu(Circular);

int main(){

    Circular p=nuevaC();

    srand ( time(NULL) );
    int i,j=random(10,15);
    printf("===NUMERO DE PROCESOS: %d===\n",j);
    for(i=0;i<j;i++){
        p=formarC(p,random(5,15));
    }

    while(!esnuevaC(p)){
        printf("======PROCESOS=====\n");
        p=printQu(p);
        getchar();
        int r=primeroC(p)-4;
        if(EsMayor(r,0)){
            p=desformarC(p);
            p=formarC(p,r);
        }else p=desformarC(p);
    }
    printf("===PROCESOS TERMINADOS===");
    return 0;
}

int random(int min, int max){
    Circular d=nuevaC();
    int n=min;
    while(n<=max){
        d=formarC(d,n);
        n++;
    }
    
    int i;
    for(i=0;i<rand()%100;i++){
        d=rotar(d);
    }
    return primeroC(d);
}

Circular printQu(Circular p){
    Circular t = nuevaC();
    while(!esnuevaC(p)){
        t=formarC(t,primeroC(p));
        ImpElem(primeroC(p));
        p=desformarC(p);
    }
    return t;
}