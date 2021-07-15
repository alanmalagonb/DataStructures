#include<stdio.h>


int main(){
    char pos[80];
    int i=0;


    while(i<5){ pos[i]=65+i; i++;}

    i=0;

    while(pos[i]) i++;

    printf("i=%d, %s.\n",i,pos);



    return 0;
}
