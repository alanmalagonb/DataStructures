typedef struct NodoAB{
                Elem r;
                struct NodoAB *i;
                struct NodoAB *d;
               }*ArBin;

ArBin vacioAB(){return NULL;}
ArBin consAB(Elem r, ArBin i, ArBin d){
     ArBin t=(ArBin)malloc(sizeof(struct NodoAB));
     t->r=r;
     t->i=i;
     t->d=d;
     return t;
}
int esvacioAB(ArBin a){return a==NULL;}
Elem raiz(ArBin a){return a->r;}
ArBin izquierdo(ArBin a){return a->i;}
ArBin derecho(ArBin a){return a->d;}


/*********************************************/

int NumElemsAB(ArBin i){
     if(esvacioAB(i))
        return 0;
     else
        return 1+NumElemsAB(izquierdo(i))+ NumElemsAB(derecho(i));
}

int MoI(int a, int b){
    if(a>=b)
        return a;
    else
        return b;
}

int Altura(ArBin a){
    if(esvacioAB(a))
        return 0;
    else
        return 1+MoI(Altura(izquierdo(a)),Altura(derecho(a)));
}

int EsHoja(ArBin a){return esvacioAB(izquierdo(a))&&esvacioAB(derecho(a));}
Elem ElemMasDerechoB(ArBin a){
     if(EsHoja(a)||esvacioAB(derecho(a)))
          return raiz(a);
     else
          return ElemMasDerechoB(derecho(a));
}

Elem ElemMasIzquierdoB(ArBin a){
     if(EsHoja(a)||esvacioAB(izquierdo(a)))
          return raiz(a);
    else
          return ElemMasIzquierdoB(izquierdo(a));
}


void ImpNivelAB(ArBin a, int nivel){
    if (esvacioAB(a))
        return;
    if (nivel == 1)
        ImpElem(raiz(a));
    else if (nivel > 1){
        ImpNivelAB(izquierdo(a), nivel-1);
        ImpNivelAB(derecho(a), nivel-1);
    }
}
void ImpNivelPorNivelAB(ArBin a){
    int h = Altura(a),i;
    for (i=1; i<=h; i++){
        ImpNivelAB(a, i);
        printf("\n");
    }
}

/*
Espec ArBin
   vacioAB:->ArBin;
   consAB:Elem,ArBin,ArBin -> ArBin;
   esvacioAB:ArBin->Bool;
   raiz:ArBin -> Elem;
   izquierdo: ArBin->ArBin;
   derecho: ArBin -> Arbin;

   Axiomas: Elem r, ArBin i,d;
      [ab1] esvacioAB(vacioAB())=Cierto;
      [ab2] esvacioAB(consAB(r,i,d))=Falso;
      [ab3] raiz(vacioAB())= ERROR;
      [ab4] raiz(consAB(r,i,d))= r;
      [ab5] izquierdo(vacioAB())= ERROR;
      [ab6] izquierdo(consAB(r,i,d))= i;
      [ab7] derecho(vacioAB())= ERROR;
      [ab8] derecho(consAB(r,i,d))= d;
   Fin ArBin.


                   5
                  / \
                 10 20
                   /
                  15

           a=consAB(5,consAB(10,vacioAB(),vacioAB()),
                      consAB(20,consAB(15,vacioAB(),vacioAB()),vacioAB()));


    int NumElemsAB(ArBin i){
     if(esvacioAB(i))
        return 0;
     else
        return 1+NumElemsAB(izquierdoAB(i))+ NumElemsAB(derechoAB(i));
}
a=consAB(5,consAB(10,vacioAB(),vacioAB()),
                      consAB(20,consAB(15,vacioAB(),vacioAB()),vacioAB()));

NumElemsAB(a)= 1+NumElemsAB(izquierdoAB(i))+ NumElemsAB(derechoAB(i));
             = 1+NumElemsAB(consAB(10,vacioAB(),vacioAB()))
               + NumElemsAB(consAB(20,consAB(15,vacioAB(),vacioAB()),vacioAB())))
  = 1+1+NumElemsAB(vacioAB())+ NumElemsAB(vacioAB())
               + 1+NumElemsAB(consAB(15,vacioAB(),vacioAB()))+ NumElemsAB(vacioAB())
= 1+1+0+0+1+1+NumElemsAB(izquierdoAB(i))+ NumElemsAB(derechoAB(i))+0
= 1+1+0+0+1+1+NumElemsAB(vacioAB())+ NumElemsAB(vacioAB())+0
= 1+1+0+0+1+1+0+0+0 = 4 :)
*/