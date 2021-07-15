typedef Lista *TablaH;

TablaH consTH(int n){
     int i;
     TablaH t=(TablaH)malloc(sizeof(Lista)*n);
     for(i=0;i<n;i++)
         t[i]=vacia();
     return t;
}

TablaH InsElem(Elem e, TablaH t, int n){
      t[Llave(e)%n]=cons(e,t[Llave(e)%n]);

      return t;
}

void ImpTablaH(TablaH t, int n){
    int i;
    for(i=0;i<n;i++){
        ImpElems(t[i]);
        puts("\n--------------");
    }
}

void Consulta(Elem e, TablaH t, int n){
    if(EstaEn(e, t[Llave(e)%n])){
        ImpElem(DevuelveElem(e, t[Llave(e)%n]));
        printf("\n");
    }
    else
         puts("Elemento no encontrado.\n");
}

void Borra(Elem e, TablaH t, int n){
    if(EstaEn(e, t[Llave(e)%n])){
        printf("Elemento eliminado:\n");
        ImpElem(DevuelveElem(e, t[Llave(e)%n]));
        t[Llave(e)%n]=EliminaElem(e,t[Llave(e)%n]);
        printf("\n");
    }
    else
         puts("Elemento no encontrado.\n");
}

/*
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

if(EstaEn(e, t[Llave(e)%n]))
        ImpElem(DevuelveElem(e, t[Llave(e)%n]));
    else
         puts("Elemento no encontrado");

void Consulta(Elem e, TablaH t){
    if(EstaEn(e, t[Llave(e)%n]))
        ImpElem(DevuelveElem(e, t[Llave(e)%n]));
    else
         puts("Elemento no encontrado");
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
