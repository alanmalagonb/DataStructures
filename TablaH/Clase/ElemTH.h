typedef struct{
      char *pais;
      char *capital;
      char *gentilicio;
      char *idioma;
      char *divisa;
      int poblacion;
      float ingreso;
} Elem;

Elem LeeElem(FILE *ent){
    Elem e;
    e.pais=(char*)malloc(20);
    e.capital=(char*)malloc(20);
    e.gentilicio=(char*)malloc(20);
    e.idioma=(char*)malloc(20);
    e.divisa=(char*)malloc(20);
    fscanf(ent,"%s",e.pais);
    fscanf(ent,"%s",e.capital);
    fscanf(ent,"%s",e.gentilicio);
    fscanf(ent,"%s",e.idioma);
    fscanf(ent,"%s",e.divisa);
    fscanf(ent,"%d",&e.poblacion);
    fscanf(ent,"%f",&e.ingreso);
    return e;
}

Elem LeeElemCons(){
    Elem e;
    e.pais=(char*)malloc(20);
    e.capital=(char*)malloc(20);
    e.gentilicio=(char*)malloc(20);
    e.idioma=(char*)malloc(20);
    e.divisa=(char*)malloc(20);
    fscanf(stdin,"%s",e.pais);
    fscanf(stdin,"%s",e.capital);
    fscanf(stdin,"%s",e.gentilicio);
    fscanf(stdin,"%s",e.idioma);
    fscanf(stdin,"%s",e.divisa);
    fscanf(stdin,"%d",&e.poblacion);
    fscanf(stdin,"%f",&e.ingreso);
    return e;
}
/*
Elem LeeElemF(FILE *ent, Elem e){
    e.sim=(char*)malloc(3);
    e.nombre=(char*)malloc(15);
    fscanf(ent,"%s%s%d%f",e.sim,e.nombre,&e.na,&e.ma);

    return e;
}
*/
void ImpElemF(FILE *sal,Elem e){
    fprintf(sal,"%s\n",e.pais);
    fprintf(sal,"%s\n",e.capital);
    fprintf(sal,"%s\n",e.gentilicio);
    fprintf(sal,"%s\n",e.idioma);
    fprintf(sal,"%s\n",e.divisa);
    fprintf(sal,"%d\n",e.poblacion);
    fprintf(sal,"%f\n",e.ingreso);
}

void ImpElem(Elem e){
    fprintf(stdout,"%s\t",e.pais);
    fprintf(stdout,"%s\t",e.capital);
    fprintf(stdout,"%s\t",e.gentilicio);
    fprintf(stdout,"%s\t",e.idioma);
    fprintf(stdout,"%s\t",e.divisa);
    fprintf(stdout,"%d\t",e.poblacion);
    fprintf(stdout,"%.2f\t",e.ingreso);
}


int EsIgual(Elem e1, Elem e2){return !strcmp(e1.pais,e2.pais);}

int Llave(Elem e){
    int n=0,i=0;
    char *p= e.pais;
    while(e.pais[i])
        n=n+e.pais[i++];

    return n;
    }
