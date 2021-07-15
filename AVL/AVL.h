#include"C:\Users\Alan\Desktop\AyEdd\DicBin\DicBin.h"

typedef DicBin AVL;

int FactBal(DicBin a){ return Altura(izquierdo(a))-Altura(derecho(a)); }

AVL rotaDer(DicBin a){
    return consAB(raiz(izquierdo(a)),izquierdo(izquierdo(a)), 
                    consAB(raiz(a),
                        derecho(izquierdo(a)),derecho(a)));
}

AVL rotaIzq(DicBin a){
    return consAB(raiz(derecho(a)),
                    consAB(raiz(a),izquierdo(a),izquierdo(derecho(a))),
                        derecho(derecho(a)));
}

AVL rotaIzqDer(DicBin a){
    return rotaDer(consAB(raiz(a),rotaIzq(izquierdo(a)),derecho(a)));
}

AVL rotaDerIzq(DicBin a){
    return rotaIzq(consAB(raiz(a),izquierdo(a),rotaDer(derecho(a))));
}

int absoluto(int n){
    if(n<0) return -n;
    else return n;
}

int EsAVL(DicBin a){
    if(esvacioAB(a))
        return 1;
    else return ((absoluto(FactBal(a))<=1)&&(EsAVL(izquierdo(a))&&EsAVL(derecho(a))));
}

AVL HazAVL(DicBin a){
    if(absoluto(FactBal(a))>1)
        if(EsAVL(izquierdo(a))&&EsAVL(derecho(a)))
            if(FactBal(a)>1)
                if(FactBal(izquierdo(a))>0)
                    return rotaDer(a);
                else 
                    return rotaIzqDer(a); 
            else if(FactBal(derecho(a))<0)
                return rotaIzq(a);
            else
                return rotaDerIzq(a);
        else if(EsAVL(izquierdo(a)))
            return consAB(raiz(a),izquierdo(a), HazAVL(derecho(a)));
        else
            return consAB(raiz(a),HazAVL(izquierdo(a)),derecho(a));
    else if(EsAVL(izquierdo(a)))
        return consAB(raiz(a),izquierdo(a),HazAVL(derecho(a)));
    else
        return consAB(raiz(a),HazAVL(izquierdo(a)),derecho(a)) ;


}


AVL InsAVL(Elem e, AVL a){
    a=insord(e,a);
    if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}

AVL ElimAVL(Elem e, AVL a){
    a=ElimElem(e,a);
    if(EsAVL(a))
        return a;
    else
        return HazAVL(a);
}