typedef struct NodoC{ Elem dato;
                     struct NodoC *sig;
               }*ApNodo;
typedef struct Cnodo{ ApNodo prim;
                ApNodo ult;
              }*Cola;

Cola nueva(){
   Cola t=(Cola)malloc(sizeof(struct Cnodo));
   t->prim=t->ult=NULL;
   return t;
}

int esnueva(Cola q){ return ((q->prim==NULL)&&(q->ult==NULL));}

Cola formar(Cola q, Elem e){
    ApNodo t=(ApNodo)malloc(sizeof(struct NodoC));
    t->dato=e; t->sig=NULL;
    if(esnueva(q))
        q->prim=q->ult=t;
    else{
        q->ult->sig=t;
        q->ult=t;
        }
    return q;
}
Elem primero(Cola q){return q->prim->dato;}
Elem ultimo(Cola q){return q->ult->dato;}
Cola desformar(Cola q){
       ApNodo t;
       if(q->prim==q->ult){
           free(q->prim); free(q); return nueva();
       }else{
           t=q->prim;
           q->prim=q->prim->sig;
           free(t);
           return q;
          }
}
