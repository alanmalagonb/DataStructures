typedef struct informacion{
    int dinero;
    int ganadas;
    int perdidas;
    int ganancias;
} * Jugador;

Jugador nuevoJugador(){ return NULL;}

Jugador crearJugador(int d){
    Jugador t = (Jugador)malloc(sizeof(struct informacion));
    t->dinero=d;
    t->ganadas=0;
    t->perdidas=0;
    t->ganancias=d;
    return t;
}

int dinero(Jugador j){return j->dinero;}
int ganadas(Jugador j){return j->ganadas;}
int ganancias(Jugador j){return (dinero(j)-(j->ganancias));}
void recargar(Jugador j,int i){j->dinero+=i; j->ganancias+=i;}
int perdidas(Jugador j){return j->perdidas;}
int puedeApostar(Jugador j, int c){return j->dinero>=c;}
void ganar(Jugador j, int c){j->dinero+=c; j->ganadas+=1;}
void perder(Jugador j, int c){j->dinero-=c; j->perdidas+=1;}
int invertir(int i){return -i;}

void resultado(Jugador j,int apuesta,int juego){
    if(juego==1){
        ganar(j,apuesta);
        puts("[!] Ganaste.\n");
    }else{
        perder(j,apuesta);
        puts("[!] Perdiste.\n");
    }
}