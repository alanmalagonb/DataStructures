#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include"ElemRuleta.h"
#include"Circular.h"
#include"Ruleta.h"
#include"Jugador.h"

void tablero(){
    puts("+----------------------------------------------------------------------------+");
    puts("|   | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 | 10) Columna 3 |");
    puts("|   |------------------------------------------------------------------------|");
    puts("| 0 | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 | 11) Columna 2 |");
    puts("|   |------------------------------------------------------------------------|");
    puts("|   | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 | 12) Columna 1 |");
    puts("+---|--------------------------------------------------------|---------------+");
    puts("    |1) Primer docena| 2) Segunda docena | 3) Tercera docena | 13) Numero    |");
    puts("    |--------------------------------------------------------|     Solo      |");
    puts("    |4) 1-18 | 5) Par| 6) Rojo | 7) Azul | 8) Impar| 9) 19-36|               |");
    puts("    +------------------------------------------------------------------------+\n");
}

void estadisticas(Jugador j){
      puts("+---------------------------------------------------+");
    printf("  Dinero: %d Ganadas: %d Perdidas: %d  \n",dinero(j),ganadas(j),perdidas(j));
      puts("+---------------------------------------------------+\n");
}

int main(){
    srand(time(0));
    puts("+===============================+");
    puts("|       BIENVENIDO A RULETA     |");
    puts("|       HECHO POR: ALANAMB      |");
    puts("+===============================+\n");

    Jugador j = nuevoJugador();
    int d=0;
    while(d==0){
        printf("Ingresa tu dinero: ");
        fflush(stdin);
        scanf("%d", &d);
        printf("\n");
    }
    j = crearJugador(d);
    
    Circular ruleta = inicializar();
    
    char c;
    int game=1;
    while(game==1){
        
        while(dinero(j)==0){
            printf("Ingresa tu dinero: ");
            fflush(stdin);
            scanf("%d", &d);
            printf("\n");
            recargar(j,d);
        }

        tablero();

        printf("[!] Dinero disponible: $%d  \n",dinero(j));

        int apuesta, cajero=0;
        while(cajero==0){
            printf("Ingresa el dinero a apostar: ");
            fflush(stdin);
            scanf("%d",&apuesta);
            if(puedeApostar(j,apuesta)==0){
                printf("[!] No tienes esa cantidad de dinero.\n");
                continue;
            } else cajero=1;
        }

        int opcion=0, empezar=0;
        while(empezar==0){
            printf("Ingrega la forma a apostar (1-13): ");
            fflush(stdin);
            scanf("%d",&opcion);
            if(EstaEn(opcion,1,13)==0){
                printf("[!] No existe esa opcion (1-13).\n");
            } else empezar = 1;
        }

        switch(opcion){
            case 1: resultado(j,apuesta,apuestaEntre(ruleta,1,12)); break;
            case 2: resultado(j,apuesta,apuestaEntre(ruleta,13,24)); break;
            case 3: resultado(j,apuesta,apuestaEntre(ruleta,25,36)); break;
            case 4: resultado(j,apuesta,apuestaEntre(ruleta,1,18)); break;
            case 5: resultado(j,apuesta,parOimpar(ruleta)); break;
            case 6: resultado(j,apuesta,rojoOazul(ruleta)); break;
            case 7: resultado(j,apuesta,!rojoOazul(ruleta)); break;
            case 8: resultado(j,apuesta,!parOimpar(ruleta)); break;
            case 9: resultado(j,apuesta,apuestaEntre(ruleta,19,36)); break;
            case 10: resultado(j,apuesta,columna(ruleta,1)); break;
            case 11: resultado(j,apuesta,columna(ruleta,2)); break;
            case 12: resultado(j,apuesta,columna(ruleta,1)); break;
            case 13: resultado(j,apuesta,numeroSolo(ruleta)); break;

            
        }
            estadisticas(j);

            if(dinero(j)==0) puts("Te quedaste sin dinero quieres recargar?: (s/n)");
            else puts("Deseas seguir apostando? (s/n)?");
            fflush(stdin);
            c=getchar();
            if(tolower(c)=='s') game = 1;
            else game = 0;
    }

    system("cls");
    puts("[!] Gracias por jugar a la ruleta.");
    puts("[!] Tus estadisticas son:");
    puts("+----------------------------------------+");
    if(ganancias(j)==0) puts("[!] Te quedaste igual.");
    else if(ganancias(j)>0) printf("\033[1;32m[!] Dinero ganado: %d\n",ganancias(j));
    else printf("[!] Dinero perdido: %d\n",invertir(ganancias(j)));

    printf("[!] Ganadas: %d\n",ganadas(j));
    printf("[!] Perdidas: %d\n",perdidas(j));
    puts("+----------------------------------------+");
    puts("\nMALAGON BAEZA ALAN ADRIAN 2CM2\n");
    return 0;

}
    
    


