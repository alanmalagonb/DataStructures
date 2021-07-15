
#include<stdio.h>

void QuickSort(int a[],  int n);
void llena(int a[], int n);
void imprime(int a[], int n);
int Particion(int a[], int n);

int main(){
	int a[1000], p, n;
	printf("Escriba el tamaño del arreglo\n");
	scanf("%d", &n);
	llena( a,  n);
	fflush(stdin);
	QuickSort(a, n);
	imprime(a,  n);

	return 0;
}

void QuickSort(int a[], int n){
	int p;
	if (n>1){
        p=Particion(a,n);
		QuickSort(a, p);
		QuickSort(a+p+1, n-p-1);
	}
}
void llena(int a[], int n){
    int i;
    for (i=0; i<n;i++){
        printf("Escriba el numero %d\n", i);
        scanf("%d",&a[i]);
    }
}
void imprime(int a[], int n){
    int i;
    for (i=0; i<n;i++)
         printf("%d ", a[i]);
    printf("\n");
}

int Particion(int a[], int n){
	int p=0, q=1, t, i;

	for(q=1;q<n;q++){
        if(a[q]<=a[p]){
            t=a[q];
            for(i=q;i>p;i--)
                a[i]=a[i-1];
            a[p]=t; p++;
        }
	}
	return p;
}


