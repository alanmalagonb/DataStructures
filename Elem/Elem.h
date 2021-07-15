typedef char* Elem;

void ImpElem(Elem e){printf("%s\n",e);}
Elem LeeElem(){
    Elem e=(Elem)malloc(sizeof(char)*80);
    scanf("%s",e); return e;}
int EsIgual(Elem e1, Elem e2){return strcmp(strlwr(e1),(e2))==0;}
int EsMenor(Elem e1, Elem e2){return strcmp(strlwr(e1),strlwr(e2))<0;}
int EsMayor(Elem e1, Elem e2){return strcmp(strlwr(e1),strlwr(e2))>0;}

void intercambia(Elem e1, Elem e2){
    //printf("e1=%p, e2=%p\n",e1,e2);
    Elem t=(Elem)malloc(sizeof(char)*80);
    strcpy(t,e1);
    strcpy(e1,e2);
    strcpy(e2,t);
    free(t);
    //printf("ie1=%p, ie2=%p\n",e1,e2);
}

// //tydef int Elem
// typedef char* Elem;

// void ImpElem(Elem e){printf("%s\n",e);}
// //Elem LeeElem(){Elem e; scanf("%d",&e); return e;}
// Elem LeeElem(){
//     Elem e=(Elem)malloc(sizeof(char)*80);
//     scanf("%s",e);return e;
// }

// //int EsIgual(Elem e1, Elem e2){return e1==e2;}
// int EsIgual(Elem e1, Elem e2){return strcmp(e1,e2)==0;}

// //int EsMenor(Elem e1, Elem e2){return e1<e2;}
// int EsMenor(Elem e1, Elem e2){return strcmp(e1,e2)<0;}

// //int EsMayor(Elem e1, Elem e2){return e1<e2;}
// int EsMayor(Elem e1, Elem e2){return strcmp(e1,e2)>0;}

// //void  intercambia(Elem e1, Elem e2){Elem t=e1; e1=e2; e2=t;}
// void  intercambia(Elem e1, Elem e2){
//     Elem t; 
//     strcpy(t,e1);
//     strcpy(e1,e2); 
//     strcpy(e2,t);
// }
