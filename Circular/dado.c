#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemCirc.h"
#include"C:\Users\Alan\Desktop\AyEdd\Circular\Circular.h"

int dado(){
    Circular d=nuevaC();;
    int n=1;
    while(n<=6){
        d=formarC(d,n);
        n++;
    }
    
    int i=(rand()%347)+1;
    while(i>0){
        d=rotar(d);
        i--;
    }

    return primeroC(d);
;}

int main(){
    srand(time(0));
    while(1){
        printf("%d\n",dado());
        getchar();
    }
}

