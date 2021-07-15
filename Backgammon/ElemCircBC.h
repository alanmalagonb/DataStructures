typedef int Elem;

void ImpElem(Elem e){printf("%d ",e);}
void ImpElemColor(Elem x) {
    if(x>0) printf("");
    else if(x<0) printf("");
    else if(x==0) printf("");
    ImpElem(x);
    printf("");
}