void burbuja(Elem a[], int n){
    //printf("Arreglo a:\n");
    //ImpArreglo(a,n);
    
    int i,j;

    for(j=0;j<n-1;j++){
      //printf("j=%d",j);
      for(i=n-1;i>j;i--){
        //printf("i=%d",i);
        //printf("a[i]=%s, a[i-1]=%s\n",a[i],a[i-1]);
        //printf("EsMenor=%d\n",EsMenor(a[i],a[i-1]));
        if(EsMenor(a[i],a[i-1])){
          //printf("Si Es Menor\n");
          
          //printf("a+i=%p, a+x=%p\n",a+i,a+x);
          intercambia(a[i],a[i-1]);
          //printf("a[i]=%s, a[i-1]=%s\n",a[i],a[i-1]);
        }
      }
    }
       
         
            
}

void insercion(Elem a[],int n){
  int j,i;
  for(j=1;j<n;j++){
    i=j;
    //for(;i>0;i--)
    while((i>0)&&EsMenor(a[i],a[i-1])){
      intercambia(a[i],a[i-1]);
      i--;
    }
  }
    
}
/*
{
             printf("%d\n",EsMenor(a[i],a[i-1]));
             fflush(stdin);
             ImpElem(a[i]); ImpElem(a[i-1]);
             getchar();
             intercambia(a[i],a[i-1]);
             ImpElem(a[i]); ImpElem(a[i-1]);
             getchar();
         }

*/
