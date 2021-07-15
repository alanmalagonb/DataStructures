typedef Lista * TablaH;

TablaH consTH(int n){
    int i;
    TablaH t = (TablaH)malloc(sizeof(Lista)*n);
    for(i=0;i<n;i++)
        t[i]=vacia();
    return t;
}

TablaH InsElem(TablaH t, int n, Elem e){
      int i=Llave(e)%n;
      t[i]=cons(e,t[i]);
      return t;
}

void ImpTablaH(TablaH t,int n){
    int i;
    for(i=0;i<n;i++){
        ImpElems(t[i]);
        puts("----------");
    }
}


/*
TablaH EliminaElemTH(TablaH t,int n, char *ident){
    Elem e;
    int key;

    e.pais=(char*)malloc(25);
    strcpy(e.pais,ident);
    key= LLave(e,n);
    if(EstaEn(e,t[key]))
        t[key]=EliminaElem(e,t[key]);
    return t;
}

TablaH EliminaElemTH(TablaH t, int n, char *ident){
       Elem e;
       int key;

       e.sim=(char*)malloc(3);
       strcpy(e.sim,ident);
       key = Llave(e,n);
       if(EstaEn(e,t[key]))
           t[key]=EliminaElem(e,t[key]);
       return t;
}

void Consulta2(Elem e, Lista l){
    if(EsIgual(e,cabeza(l)))
                 ImpElem(cabeza(l));
            else
                Consulta2(e, resto(l));
}

void Consulta(char *ident, TablaH t, int n){
       Elem e;
       int key;

       e.sim=(char*)malloc(3);
       strcpy(e.sim,ident);
       key = Llave(e,n);
       if(EstaEn(e,t[key]))
           Consulta2(e,t[key]);
       else
            puts("Elemento no encontrado.");
}
*/
