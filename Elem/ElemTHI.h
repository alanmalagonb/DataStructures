typedef struct{
    char *sim;
    char *nombre;
    int na;
    float ma;
}Elem;

Elem LeeElem(){
    Elem e;
    e.sim=(char*)malloc(3);
    e.nombre=(char*)malloc(15);
    scanf("%s",e.sim);
    scanf("%s",e.nombre);
    scanf("%d",e.na);
    scanf("%f",e.ma);
}

Elem LeeElemF(FILE *ent){
    Elem e;
    e.sim=(char*)malloc(3);
    e.nombre=(char*)malloc(15);
    fscanf(ent,"%s%s%d%f",e.sim,e.nombre,&e.na,&e.ma);
    return e;
}
void ImpElem(Elem e){
    printf("%s\t%s\t%d\t%3.2f\n",e.sim,e.nombre,e.na,e.ma);
}

int EsIgual(Elem e1, Elem e2){ return !strcmp(e1.sim,e2.sim);}
int esMenor(Elem e1, Elem e2){
	return e1.sim < e2.sim;
}