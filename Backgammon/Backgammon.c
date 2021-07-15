#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include"ElemCircBC.h"
#include"CircularBC.h"

//CREA EL TABLERO CON UNA COLA CIRCULAR
Circular inicializa(){
    Elem fichas[16]={0,-2,4,5,1,3,3,-5,0,5,3,-3,1,-5,4,2};
    //Elem fichas[16]={0,-1,4,1,1,1,3,-1,0,1,3,-1,1,-1,4,1};
    //Elem fichas[16]={0,0,4,1,1,0,3,0,0,0,3,0,1,-1,4,0};
    int i,j;
    Circular t=nuevaC();
    for(i=0;i<16;i+=2){
        for(j=fichas[i];j>0;j--) formarC(t,0);
        formarC(t,fichas[i+1]);
    }
    return t;
}

//IMPRIMER EL TABLERO
void ImpTablero(Circular c){
    int i,n=0;
    int co;
    printf("  ");
    for(co=12;co>0;co--){
        if(co<10) putchar(' ');
        printf("%d ",co);
    } 
    printf("\n");
    while(n<3){
        if(n==0) printf("A "); else printf("B ");
        for(i=0;i<11+n;i++){rotaIzq(c);};
        for(i=0;i<12;i++){
            if(primeroC(c)>=0) putchar(' ');
            ImpElemColor(primeroC(c));//ImpElem(primeroC(c));
            if(n==0) rotaDer(c);
            else rotaIzq(c);
        } printf("\n"); n+=2;
    }    
}

int dado(){
    Circular d=nuevaC();
    int n=1;
    while(n<=6){d=formarC(d,n);n++;}
    int i=(rand()%347)+1;
    while(i>0){d=rotaIzq(d);i--;}
    return primeroC(d);
}

//CALCULA DESPLAZAMIENTO DADAS COORDENADAS
int movimientos(char c, int i){
    if(c=='B') return i=25-i;
    return i;
}

//VERIFICAR SI ALGUN JUGADOR YA LLEVO TODAS SUS FICHAS A LA META
int checarGanador(Circular tablero){
    if(primeroC(tablero)==15) return 1;
    else if(primeroC(rotaDer(tablero))==-15) return 1;
    rotaIzq(tablero);
    return 0;
}

//VERIFICAR SI PUEDE MOVER UNA FICHA DADOS SUS DADOS
int checarMovsDisponiblesP1(Circular tablero,int d1,int d2){
    int i, mov=0;
    //printf("d1:%d d2:%d",d1,d2);
    for(i=0;i<24;i++){
        if(primeroC(tablero)<0){
            //printf("primer tab:%d\n",primeroC(tablero));
            //printf("sum1: %d\n",i+d1);
            if(i+d1<=23 && d1!=0){
                //printf("sum1: %d\n",i+d1);
                int j,l=d1;
                for(j=0;j<l;j++){
                    rotaIzq(tablero);
                }
                if(primeroC(tablero)<=1) mov++;
                //printf("mov: %d\n",mov);
                while(l>0){ rotaDer(tablero); l--;}
            }
            //printf("primer tabd2:%d\n",primeroC(tablero));
            //printf("sum2: %d\n",i+d2);
            if(i+d2<=23 && d2!=0){
                //printf("sum2: %d\n",i+d2);
                int k,m=d2;
                for(k=0;k<m;k++){
                    rotaIzq(tablero);
                }
                if(primeroC(tablero)<=1) mov++;
                //printf("mov: %d\n",mov);
                while(m>0){ rotaDer(tablero); m--;}
            }
            
            rotaIzq(tablero);
        }else rotaIzq(tablero);
    }
    //printf("mov: %d\n",mov);
    if(mov!=0) return 1;
    else return 0;
}

//CHECAR SI ES DEL MISMO EQUIPO O ESTA DISPONIBLE EL ESPACIO
int checarMovP1(Circular c, int m, int d){
    //printf("M = %d\n", m);
    int i, r=0;
    if(d==0) return 0;
    for(i=1;i<25;i++){
        if(i==m){
            //printf("m = %d\n", primeroC(c));
            if(i+d<=24){
                if(primeroC(c)<0){
                int j,l=d;
                for(j=0;j<l;j++){
                    rotaIzq(c);
                }
                //printf("C = %d\n", primeroC(c));
                if(primeroC(c)>1) r=0;
                else r=1;
                while(l>0){ rotaDer(c); l--;}
                }
            }
            rotaIzq(c);
        }else rotaIzq(c); 
    }
    
    //printf("R = %d\n", r);
    return r;
}

//AUMENTA-DISMINUYE LAS FICHAS POR EL MOVIMIENTO
void MovP1(Circular c, int m, int d){
    //printf("M = %d\n", m);
    int i,comio=0;
    for(i=1;i<25;i++){
        if(i==m){
            //printf("m = %d\n", primeroC(c));                
                aumentar(c);
                int j,l=d;
                for(j=0;j<l;j++){
                    rotaIzq(c);
                }
                if(primeroC(c)==1){
                    comio=1; disminuir(c);
                }
                //printf("C = %d\n", primeroC(c));
                disminuir(c);
                while(l>0){ rotaDer(c); l--;}
                rotaIzq(c);
        }else rotaIzq(c); 
    }
    if(comio==1){
        int k=1;
        while(primeroC(c=rotaDer(c))<=-1){
            k++;
        } 
        aumentar(c);
        while(k>0){ rotaIzq(c); k--;}
    }
    
}

int checarMovsDisponiblesP2(Circular tablero,int d1,int d2){
    int i, mov=0;
    for(i=0;i<24;i++){
        if(primeroC(tablero)>0){
            if(i-d1>=0  && d1!=0){
                int j,l=d1;
                for(j=0;j<l;j++){
                    rotaDer(tablero);
                }
                if(primeroC(tablero)>=-1) mov++;
                while(l>0){ rotaIzq(tablero); l--;}
            }
            
            if(i-d2>=0  && d2!=0){
                int k,m=d2;
                for(k=0;k<m;k++){
                    rotaDer(tablero);
                }
                if(primeroC(tablero)>=-1) mov++;
                while(m>0){ rotaIzq(tablero); m--;}
            }

            rotaIzq(tablero);
        }else rotaIzq(tablero);
    }
    if(mov!=0) return 1;
    else return 0;
}

int checarMovP2(Circular c, int m, int d){
    //printf("M = %d\n", m);
    int i, r=0;
    if(d==0) return 0;
    for(i=1;i<25;i++){
        if(i==m){
            if(m-d>=1){
                if(primeroC(c)>0){
                int j,l=d;
                for(j=0;j<l;j++){
                    rotaDer(c);
                }
                //printf("C = %d\n", primeroC(c));
                if(primeroC(c)< -1) r=0;
                else r=1;
                while(l>0){ rotaIzq(c); l--;}
                }
            }
            //printf("m = %d\n", primeroC(c));
    
        }else rotaIzq(c); 
    }
    rotaIzq(c);
    //printf("R = %d\n", r);
    return r;
}

void MovP2(Circular c, int m, int d){
    //printf("M = %d\n", m);
    int i,comio=0;
    for(i=1;i<25;i++){
        if(i==m){
            //printf("m = %d\n", primeroC(c));
                disminuir(c);
                int j,l=d;
                for(j=0;j<l;j++){
                    rotaDer(c);
                }
                if(primeroC(c)==-1){
                    comio=1; aumentar(c);
                }
                //printf("C = %d\n", primeroC(c));
                aumentar(c);
                while(l>0){ rotaIzq(c); l--;}
                rotaIzq(c);
        }else rotaIzq(c); 
    }
    
    if(comio==1){
        int k=0;
        while(primeroC(c)>0){
            rotaIzq(c);
            k++;
        } 
        disminuir(c);
        while(k>0){ rotaDer(c); k--;}
    }
}

//IMPRIME COLOR PARA CADA JUGADOR
void imprimirJugador(char c[],int i,char n[]){
    if(i==1){
        printf("");
        printf("[J1: %s (Fichas negativas) ] %s",n,c);
        printf("\n");
    }else{
        printf("");
        printf("[J2: (Fichas positivas)%s] %s",n,c);
        printf("\n");
    }
};

//EMPEZAR JUEGO
int start(){
    char j1[20],j2[20];
    puts("+===============================+");
    puts("|    BIENVENIDO A BACKGAMMON    |");
    puts("|       HECHO POR: ALANAMB      |");
    puts("+===============================+\n");

    imprimirJugador("Ingresa tu nombre: ",1,"?");
    scanf("%s", j1);
    printf("\n");
    imprimirJugador("Ingresa tu nombre: ",2,"?");
    scanf("%s", j2);



    puts("\n+=========INSTRUCCIONES=========+");
    puts("|1-Puedes avanzar a las casillas|");
    puts("|  de tu color o con un cero.   |");
    puts("|2-Puedes comerte al otro       |");
    puts("| jugador si solo tiene 1 ficha.|");
    puts("| Las fichas del otro jugador   |");
    puts("| seran enviadas a su inicio.   |");
    puts("|3-Para ganar debes llevar todas|");
    puts("|  tus fichas a tu meta.        |");
    puts("+===============================+");
    puts("\nContinuar... (Presiona enter)");
    fflush(stdin);
    getchar();
    puts("+============TABLERO============+");
    puts("|           JUGADOR 1           |");
    puts("| <- <- <- <- <- <- <- <- INICIO| ");
    puts("| -> -> -> -> -> -> -> ->  META | ");
    puts("|           JUGADOR 2           |");
    puts("| -> -> -> -> -> -> -> ->  META |");
    puts("| <- <- <- <- <- <- <- <- INICIO|");
    puts("+===============================+\n");
    puts("Empezar juego... (Presiona enter)");
    fflush(stdin);
    getchar();

    Circular tablero = inicializa();
    int p1,p2,turno=1;
    int d1,d2;
    char c1; int c2; int ds; int dn;
    do{
        if(turno==1){
            imprimirJugador("Es tu turno.\n",1,j1);
            
            d1=dado(),d2=dado();
            
            do{
                ImpTablero(tablero);
                if(checarGanador(tablero)==1){
                    puts("\n");
                    imprimirJugador("Eres el ganador.\n",1,j1);
                    return 1;
                }//else puts("Aun no ganas");
                
                printf("\n[J1: %s] Tus dados son: Dado 1: %d Dado 2: %d\n",j1,d1,d2);
                if(checarMovsDisponiblesP1(tablero,d1,d2) == 0){
                    imprimirJugador("No tienes movimientos disponibles.\n",1,j1);
                    d1=0; d2=0;
                    continue;
                }
                /*
                else{
                    imprimirJugador("Tienes movimientos disponibles.",1,j1);
                } */
                
                imprimirJugador("Inserta coordenadas de ficha a mover y dado: (A 12 1) (B 4 2)",1,j1);
                fflush(stdin);
                scanf("%c",&c1);
                scanf("%d",&c2);
                scanf("%d",&dn);

                //printf("F: %c C: %d D:%d\n",c1,c2,dn);                
                if(!(tolower(c1)=='a' || tolower(c1)=='b') || (c2<0 || c2>12) || !(dn==1 || dn==2)){
                    imprimirJugador("Algun dato es erroneo\n",1,j1);
                    continue;
                } 

                if(dn==1) ds=d1;
                else if(dn==2) ds=d2;
                printf("\n");
                if(checarMovP1(tablero, movimientos(c1,c2),ds)==1){
                    imprimirJugador("Movimiento Realizado.\n",1,j1);
                    MovP1(tablero, movimientos(c1,c2),ds);
                    //printf("ds: %d\n",dn);
                    if(dn==1) d1=0;
                    else if(dn==2) d2=0;
                }else imprimirJugador("No puedes hacer ese movimiento. Intentalo de nuevo.\n",1,j1);
                //printf("d1:%d\n",d1);
                //printf("d2:%d\n",d2);
            }while(d1!=0 || d2!=0);
                ImpTablero(tablero);
                printf("\n");
                imprimirJugador("Turno Terminado.\n",1,j1);
                imprimirJugador("Presiona enter para continuar...",2,j2);
                fflush(stdin); getchar();
                turno=2;
        }else{
            imprimirJugador("Es tu turno.\n",2,j2);
            
            d1=dado(),d2=dado();
            
            do{
                ImpTablero(tablero);
                if(checarGanador(tablero)==1){
                    puts("\n");
                    imprimirJugador("Eres el ganador.\n",2,j2);
                    return 1;
                }//else puts("Aun no ganas");
                
                printf("\n[J2: %s] Tus dados son: Dado 1: %d Dado 2: %d\n",j2,d1,d2);
                if(checarMovsDisponiblesP2(tablero,d1,d2) == 0){
                    imprimirJugador("No tienes movimientos disponibles.\n",2,j2);
                    d1=0; d2=0;
                    continue;
                }
                /*
                else{
                    imprimirJugador("Tienes movimientos disponibles.",2,j2);
                } */
                
                imprimirJugador("Inserta coordenadas de ficha a mover y dado: (A 12 1) (B 4 2)",2,j2);
                fflush(stdin);
                scanf("%c",&c1);
                scanf("%d",&c2);
                scanf("%d",&dn);

                if(!(tolower(c1)=='a' || tolower(c1)=='b') || (c2<0 || c2>12) || !(dn==1 || dn==2)){
                    imprimirJugador("Algun dato es erroneo\n",2,j2);
                    continue;
                } 

                if(dn==1) ds=d1;
                else if(dn==2) ds=d2;
                
                printf("\n");
                if(checarMovP2(tablero, movimientos(c1,c2),ds)==1){
                    imprimirJugador("Movimiento Realizado.\n",2,j2);
                    MovP2(tablero, movimientos(c1,c2),ds);
                    //printf("ds: %d\n",dn);
                    if(dn==1) d1=0;
                    else if(dn==2) d2=0;
                }else{
                    imprimirJugador("No puedes hacer ese movimiento. Intentalo de nuevo.\n",2,j2);
                    continue;
                } 
                //printf("d1:%d\n",d1);
                //printf("d2:%d\n",d2);
            }while(d1!=0 || d2!=0);
            ImpTablero(tablero);
            printf("\n");
            imprimirJugador("Turno Terminado.\n",2,j2);
            imprimirJugador("Presiona enter para continuar...",1,j1);
            fflush(stdin); 
            getchar();
            turno=1;
        }
    }while(p1!=15 || p2!=15);
    //printf("%d\n",dado());
}

int main(){
    int juego=1;
    while(juego==1){
        start();
        puts("Desean jugar otra vez? (s/n)?");
        fflush(stdin);
        char c;
        c=getchar();
        printf("lower: %c",tolower(c));
        puts("\n");
        system("cls");
    }
    puts("\nMALAGON BAEZA ALAN ADRIAN 2CM2");
    return 0;
}