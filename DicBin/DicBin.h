#include"C:\Users\Alan\Desktop\AyEdd\ArBin\ArBin.h"

typedef ArBin DicBin;

DicBin insord(Elem e, DicBin d){
     if(esvacioAB(d))
        return consAB(e,vacioAB(),vacioAB());
     else if(EsMenor(e,raiz(d)))
             return consAB(raiz(d),insord(e,izquierdo(d)),derecho(d));
          else
             return consAB(raiz(d),izquierdo(d),insord(e,derecho(d)));
}

void InOrder(DicBin d){
     if(!esvacioAB(d)){
        InOrder(izquierdo(d));
        ImpElem(raiz(d));
        InOrder(derecho(d));
     }
}

void PreOrder(DicBin d){
     if(!esvacioAB(d)){
        ImpElem(raiz(d));
        InOrder(izquierdo(d));
        InOrder(derecho(d));
     }
}

void PostOrder(DicBin d){
     if(!esvacioAB(d)){
        PostOrder(izquierdo(d));
        PostOrder(derecho(d));
        ImpElem(raiz(d));
     }
}

// EstaEn(e,a)=Cierto
DicBin ElimElem(Elem e, DicBin a){
      if(EsIgual(e,raiz(a)))
         if(esvacioAB(izquierdo(a)))
             return derecho(a);
         else if(esvacioAB(derecho(a)))
                 return izquierdo(a);
              else
                 return consAB(ElemMasDerechoB(izquierdo(a)),
                               ElimElem(ElemMasDerechoB(izquierdo(a)),izquierdo(a)),
                               derecho(a));
      else if(EsMenor(e,raiz(a)))
              return consAB(raiz(a),ElimElem(e,izquierdo(a)),derecho(a));
           else
              return consAB(raiz(a),izquierdo(a),ElimElem(e,derecho(a)));
}

/*
Espec DicBin
     Usa todo de ArBin;
     insord:Elem, DicBin -> DicBin;
   Axiomas: Elem e, DicBin d;
     [db1] esvacioAB(insord(e,d))= Cierto;
     [db1] raiz(insord(e,d))= e;
     [db3] izquierdo(insord(e,d))=Si esmenor(e,raiz(d))
                                    ret insord(e,izquierdo(d));
                                  sion
                                    ret izquierdo(d);
     [db4] derecho(insord(e,d)) Si es menor(e,raiz(d))
                                    ret derecho(d);
                                sino
                                    ret insord(e,derecho(d));
Fin DicBin.
*/
