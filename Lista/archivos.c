#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemStr.h"
#include"C:\Users\Alan\Desktop\AyEdd\Lista\Lista.h"

int main(int argc, char *argv[]){
    char pal1[80], *pal2;
    FILE *ent= fopen(*(argv+1),"r");
    Lista a=vacia();

    while(fscanf(ent,"%s",pal1)!=-1){
        pal2=(char*)malloc(sizeof(char)*80);
        strcpy(pal2,pal1);
        a=cons(pal2,a);
    }
    
    ImpLista(OrdenaListaAsc(a));

    return 0;
}
//& .\"archivos.exe" texto.txt
/*int main(int argc, char *argv[]){
    char pal[80];
    FILE *ent= fopen(*(argv+1),"r");
    while(fscanf(ent,"%s",pal)!=-1)
        fprintf(stdout,"%s\n",pal);
    return 0;
}/*

/*int main(int argc, char *argv[]){
    char pal[80];
    FILE *ent= fopen(*(argv+1),"r");
    while(fscanf(ent,"%s",pal)!=-1)
        printf("%s\n",pal);
    return 0;
}*/


/*int main(int argc, char *argv[]){
    char c;
    FILE *ent= fopen(*(argv+1),"r");
    while((c=fgetc(ent))!=EOF)
        putchar(c);
    return 0;
}*/

/*int main(){
    char c;
    FILE *ent= fopen("texto.txt","r");
    while((c=fgetc(ent))!=EOF)
        putchar(c);
    return 0;
}*/