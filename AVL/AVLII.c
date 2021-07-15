#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemAVL.h"
#include"C:\Users\Alan\Desktop\AyEdd\AVL\AVL.h"

int main(){
    Elem e;
    DicBin a=vacioAB();
    int i;

    for(i=1;i<50000;i++){
        a=InsAVL(i,a);
        printf("i=%d\tFb=%d\n",i,FactBal(a));
        puts("");
        getchar();
    }

    /*do{
        printf("Dame un elemento (0 para salir)!!!");
        e=LeeElem();
        a=insord(e,a);
        EsAVL(a)?printf("Factor de balanceo: %d.\n",FactBal(a)):printf("Factor de balanceo: %d.\n",FactBal(a));
        if(EsAVL(a))
            printf("No hay que rebalancear.\n");
        else{
            printf("Hay que rebalancear.\n");
            a=HazAVL(a);
            printf("Factor de balanceo: %d.\n",FactBal(a));
        }
    }while(e);
    */
    return 0;
}

