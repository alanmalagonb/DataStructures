typedef char* Elem;

void ImpElem(Elem e){printf("%s\n",e);}

int EsIgual(Elem e1, Elem e2){
    if(strcmp(e1,e2)==0) return 1;
    else return 0;
}

int EsMenor(Elem e1, Elem e2){
    if(strcmp(e1,e2) < 0) return 1;
    else return 0;
}