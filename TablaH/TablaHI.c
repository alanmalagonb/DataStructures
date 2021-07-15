#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemTHI.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\ListaH.h"
#include"C:\Users\Alan\Desktop\AyEdd\TablaH\TablaH.h"


int main(int argc, char *argv[]){
    int n = 7;
    Elem e[n];
    int i;
    TablaH TP=consTH(143);
    FILE *ent=fopen(*++argv,"r");

    for(i=0;i<n;i++)
        e[i]=LeeElemF(ent);

    for(i=0;i<n;i++)
        ImpElem(e[i]);

    return 0;
}
