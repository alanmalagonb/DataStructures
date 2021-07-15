typedef int Elem;

void ImpElem(Elem e){printf("%d ",e);}
void ImpElemColor(Elem x) {
    if(x>0) printf("\033[1;33m");
    else if(x<0) printf("\033[1;31m");
    else if(x==0) printf("\033[0;37m");
    ImpElem(x);
    printf("\033[0;37m");
}