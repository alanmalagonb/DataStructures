Circular girarRuleta(Circular ruleta){
    int giro = (rand()%364)+1;
    while(giro>0){
        ruleta = rotar(ruleta);
        giro--;
    }
    return ruleta;
}

Circular inicializar(){

    Circular ruleta = nuevaC();
    Elem numeros[37]={{0,0}, {32,1}, {15,2}, {19,1}, {4,2}, {21,1}, {2,2}
                    , {25,1}, {17,2}, {34,1}, {6,2}, {27,1}, {13,2}
                    , {36,1}, {11,2}, {30,1}, {8,2}, {23,1}, {10,2}
                    , {5,1}, {24,2}, {16,1}, {33,2}, {1,1}, {20,2}
                    , {14,1}, {31,2}, {9,1}, {22,2}, {18,1}, {29,2}
                    , {7,1}, {28,2}, {12,1}, {35,2}, {3,1}, {26,2}};
    Elem t;
    //t.numero=0; t.color=0; numeros[0]=t; ruleta = formarC(ruleta,t);
    int i=0;
    while(i<37){
        ruleta = formarC(ruleta,numeros[i]);
        i++;
    }

    return ruleta;
}

Elem imprimirRuleta(Circular r){
    printf("\n> ");
    int i=37;
    while(i>0){
        ImpElemColor(primeroC(r));
        r = rotar(r);
        i--;
    }
    puts("\n");
    printf("[!] La ruleta se paro en el numero: ");
    ImpElemColor(primeroC(r));
    puts("");
    return primeroC(r);
}

int apuestaEntre(Circular ruleta,int i,int j){
    Elem suerte = imprimirRuleta(girarRuleta(ruleta));
    return EstaEntre(suerte,i,j);
}

int numeroSolo(Circular ruleta){
    int numero=0, siguiente=0;
        while(siguiente==0){
            printf("Ingrega el numero al que vas a apostar (0-36): ");
            fflush(stdin);
            scanf("%d",&numero);
            if(EstaEn(numero,0,36)==0){
            printf("[!] No existe ese numero a apostar (0-36).\n");
        } else siguiente = 1;
    }
    Elem suerte = imprimirRuleta(girarRuleta(ruleta));
    return EsIgual(suerte,numero);
}

int parOimpar(Circular ruleta){
    Elem suerte = imprimirRuleta(girarRuleta(ruleta));
    return EsPar(suerte);
}

int rojoOazul(Circular ruleta){
    Elem suerte = imprimirRuleta(girarRuleta(ruleta));
    return EsRojo(suerte);
}

int columna(Circular ruleta, int columna){
    int suerte = numeroCasilla(imprimirRuleta(girarRuleta(ruleta)));
    while(suerte>3) suerte-=3;
    if(columna==suerte) return 1;
    else return 0;
}