/*
void LeeArrElems(Elem a[], int n){
    int i;
    for (i=0; i<n;i++){
        a[i]=(Elem)malloc(20);
        printf("Escriba el elemento %d\n", i);
        LeeElem(a[i]);
    }
}
*/
int LeeArrElemsN(Elem a[]){
    int i=0;
    while((a[i]=getchar())!='\n') i++;
    i;
    a[i]='\0';
    return i;
}
/*
void ImpArrElems(Elem a[], int n){
    int i;
    for (i=0; i<n;i++)
         ImpElem(a[i]);
}
*/
