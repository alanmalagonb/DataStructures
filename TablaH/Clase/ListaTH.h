typedef struct Nodo{
      Elem dato;
      struct Nodo *sig;
} *Lista;


Lista vacia(){return NULL;}
Lista cons(Elem e, Lista l){
     Lista temp =(Lista)malloc(sizeof(struct Nodo));
     temp->dato=e;
     temp->sig=l;
     return temp;
}

int esvacia(Lista l){ return l==NULL;}

Elem cabeza(Lista l){return l->dato;}

Lista resto(Lista l ){return l->sig;}

int NumElems(Lista l){
    if(esvacia(l))
        return 0;
    else
        return 1+NumElems(resto(l));
};

void ImpElems(Lista l){
   if(!esvacia(l)){
        ImpElem(cabeza(l));
        printf("\n");
        ImpElems(resto(l));
   }
};

int EstaEn(Elem e, Lista l){
    if(esvacia(l))
        return 0;
    else if(EsIgual(e,cabeza(l)))
            return 1;
         else
            return EstaEn(e,resto(l));
}
/* Solo invocar si EstaEn(e,l)==Verdadero */
Lista EliminaElem(Elem e, Lista l){
    if(EsIgual(e,cabeza(l)))
           return resto(l);
    else
           return cons(cabeza(l),EliminaElem(e,resto(l)));
}

Elem DevuelveElem(Elem e, Lista l){
    if(EsIgual(e,cabeza(l)))
        return cabeza(l);
    else
        return DevuelveElem(e, resto(l));
}



