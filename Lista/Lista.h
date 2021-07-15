typedef struct NodoL{
                Elem dato;
                struct NodoL *sig;
              }*Lista;

Lista vacia(){return NULL;}

Lista cons(Elem e, Lista l){
    Lista t=(Lista)malloc(sizeof(struct NodoL));
    t->dato=e;
    t->sig=l;
    return t;
}

int esvacia(Lista l){return l==NULL;}

Elem cabeza(Lista l){return l->dato;}

Lista resto(Lista l){return l->sig;}

// NumElems: Lista -> int;

int NumElems(Lista l){
     if(esvacia(l))
        return 0;
     else
        return 1+NumElems(resto(l));
}

// ImpLista: Lista

void ImpLista(Lista l){
    if(!esvacia(l)){
        ImpElem(cabeza(l));
        ImpLista(resto(l));
    }
}

Lista PegaListas(Lista l1, Lista l2){
         if(esvacia(l1))
                return l2;
         else
               return cons(cabeza(l1), PegaListas(resto(l1),l2));
}

Lista InvierteLista(Lista l){
     if(esvacia(l))
         return l;
    else
        return PegaListas(InvierteLista(resto(l)), cons(cabeza(l),vacia()));

}

Lista InsOrd(Elem e, Lista l){
    if(esvacia(l))
        return cons(e,l);
    else if(EsMenor(e,cabeza(l)))
             return cons(e,l);
         else
             return cons(cabeza(l),InsOrd(e,resto(l)));
}

Lista  OrdenaListaAsc(Lista l){
       if(esvacia(l))
              return l;
      else
            return InsOrd(cabeza(l),OrdenaListaAsc(resto(l)));
}

Lista OrdenaListaDesc(Lista l){ return InvierteLista(OrdenaListaAsc(l));}

int EstaEn(Elem e, Lista l){
    if(esvacia(l))
         return 0;
    else if(EsIgual(e,cabeza(l)))
              return 1;
         else
              return EstaEn(e,resto(l));
}

int IgualTamano(Lista l1, Lista l2){
    return NumElems(l1)==NumElems(l2);
}

int SonIguales(Lista l1, Lista l2){
      if(esvacia(l1)&&esvacia(l2))
           return 1;
      else if((esvacia(l1))&&(!esvacia(l2)))
                return 0;
           else if((!esvacia(l1))&&(esvacia(l2)))
                   return 0;
                else if(EsIgual(cabeza(l1),cabeza(l2)))
                        return SonIguales(resto(l1),resto(l2));
}

//PREDICADO TRUE OR FALSE
int EsPalindroma(Lista l){return SonIguales(l,InvierteLista(l));}

Lista ocurrencias(Lista l, int n){
    if(esvacia(l)) return l;
    if(cabeza(l)==n) return ocurrencias(resto(l),n);
    else return cons(cabeza(l),ocurrencias(resto(l),n));
}

Lista mayores(Lista l, int n){
    if(esvacia(l)) return l;
    if(cabeza(l)<=n) return mayores(resto(l),n);
    else return cons(cabeza(l),mayores(resto(l),n));
}

Lista intercalar(Lista l1, Lista l2){
    if(esvacia(l1) || esvacia(l2)) return l1;
    return cons(cabeza(l1),cons(cabeza(l2),intercalar(resto(l1),resto(l2))));
}



/*
Espec Lista
    Signatura (sint�ctica):
    "Constructoras:"
       vacia: -> Lista;
       cons: Elem, Lista -> Lista;
    "Observadoras:"
       esvacia: Lista -> Bool;
       cabeza: Lista -> Elem;
    "Desdobladora:"
       resto: Lista -> Lista;

     Axiom�tica (sem�ntica): Elem e, Lista l:
       [l1]esvacia(vacia()) = Cierto;
       [l2]esvacia(cons(e,l)) = Falso;
       [l3]cabeza(vacia())= ERROR;
       [l4]cabeza(cons(e,l)) = e;
       [l5]resto(vacia()) = ERROR;
       [l6]resto(cons(e,l)) = l;
    Fin Lista.
 */
