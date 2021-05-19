#include <stdlib.h>
#include <stdio.h>

int main (){
char x;
char *p;
char y;
char *puntero;
x='x';
p=&x;

printf("valor de puntero : %c \n",*p);
p=p+1;
printf("valoor de puntero: %c \n",*p);
p=p+2;
printf("el valor de puntero p: %c \n",*p);
y='y';
puntero=&y;

printf("valor de puntero: %c \n",*puntero);

return 0;
}
