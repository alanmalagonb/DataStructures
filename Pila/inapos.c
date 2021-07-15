#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\Alan\Desktop\AyEdd\Elem\ElemPila.h"
#include"C:\Users\Alan\Desktop\AyEdd\Pila\Pila.h"

int EsMinuscula(char);
int EsMayuscula(char);
int EsDigito(char);
int EsLetra(char);
int EsOperando(char);
int EsOperador(char);
int EsParIzq(char);
int EsParDer(char);

//"(a+b)!(c-d)"
int main(int argc, char *argv[]){
    char *in=*(argv+1), pos[80], c;
    Pila ops=empty();
    int i=0,j=0;

    while(in[i]){
        EsMinuscula(c=in[i])?printf("%c es minuscula.\n",c):printf("%c no es minuscula.\n",c);
        EsMayuscula(in[i])?printf("%c es mayuscula.\n",c):printf("%c no es mayuscula.\n",c);;
        EsDigito(in[i])?printf("%c es digito.\n",c):printf("%c no es digito.\n",c);
        EsLetra(in[i])?printf("%c es letra.\n",c):printf("%c no es letra.\n",c);
        EsOperando(in[i])?printf("%c es operando.\n",c):printf("%c no es operando.\n",c);
        EsOperador(in[i])?printf("%c es operador.\n",c):printf("%c no es operador.\n",c);
        EsParIzq(in[i])?printf("%c es par izq.\n",c):printf("%c no es par izq.\n",c);
        EsParDer(in[i])?printf("%c es par der.\n",c):printf("%c no es par der.\n",c);
        i++;
  /*      Si (EsOperando(in[i]))
            pos[j++]=in[i];
        Sino Si(EsOperador(in[i]))
               ProcesarOperador(in[i]);
             Sino Si(EsParIzq(in[i]))
                     Meto in[i] a la pila ops;
                  Sino
                     ProcesarParDer;
        i++;
  */  }
/*
    CopiarPila-A-pos[];

    puts(argv[1]);
    putchar(in[4]);
*/
    return 0;
}


int EsMinuscula(char c){return (c>='a')&&(c<='z');};
int EsMayuscula(char c){return (c>='A')&&(c<='Z');};
int EsDigito(char c){return (c>='0')&&(c<='9');};
int EsLetra(char c){return EsMinuscula(c)||EsMayuscula(c);};
int EsOperando(char c){return EsDigito(c)||EsLetra(c);}
int EsOperador(char c){return (c=='+')||(c=='-')||(c=='/')||(c=='*')||(c=='!');};
int EsParIzq(char c){return c=='(';};
int EsParDer(char c){return c==')';};
