#include <stdio.h>

 void main(void)
 {
    int a = -2, b = -1, c = 0, d = 1, e = 2;
    puts("\nLazy eval: primera parte:\n");
    printf(" %d  %d  %d  %d  %d\n", a, b, c, d, e);
    if(++a && ++b && ++c && ++d && ++e)
       puts("Primer if exitoso!");
    printf(" %d  %d  %d  %d  %d\n", a, b, c, d, e);
    puts("\nSegunda parte:\n");
    a = b = c = -1;
    d = 0;
    e = 1;
    printf(" %d  %d  %d  %d  %d\n", a, b, c, d, e);
    if(++a || ++b || ++c || ++d || ++e)
       puts("Segundo if exitoso!");
    printf(" %d  %d  %d  %d  %d\n", a, b, c, d, e);
 }
