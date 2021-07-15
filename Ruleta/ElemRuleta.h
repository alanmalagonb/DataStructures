typedef struct{
    int numero; 
    int color; //Verde 0 Rojo 1 Negro 2
}Elem;

int numeroCasilla(Elem e){return e.numero;}
int colorCasilla(Elem e){return e.color;}
void ImpElem(Elem e){printf("%d ",e.numero);}
void ImpElemColor(Elem e) {
    if(e.color==0) printf("");
    else if(e.color==1) printf("");
    else if(e.color==2) printf("");
    ImpElem(e);
    printf("");
}
int EsIgual(Elem e1, int e2){return e1.numero==e2;}
int EsMenor(Elem e1, Elem e2){return e1.numero<e2.numero;}
int EsMayor(Elem e1, Elem e2){return e1.numero>e2.numero;}
int EsPar(Elem e){return e.numero%2==0;}
int EsImpar(Elem e){return e.numero%2!=0;}
int EstaEntre(Elem e,int i,int j){return (e.numero>=i)&&(e.numero<=j);}
int EstaEn(int n,int i,int j){return (n>=i)&&(n<=j);}
int EsRojo(Elem e){return e.color==1;}