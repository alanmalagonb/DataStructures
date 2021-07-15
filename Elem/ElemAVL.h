typedef int Elem;
Elem LeeElem(){
    Elem e;
    scanf("%d",&e); 
    return e;
}
void ImpElem(Elem e){printf("%d\n",e);}
int EsMenor(Elem e1, Elem e2){return e1<e2;}
int EsIgual(Elem e1, Elem e2){return e1==e2;}
int EsMoI(Elem e1, Elem e2){return e1<=e2;}