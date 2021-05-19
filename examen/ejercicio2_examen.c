#include <stdlib.h>
#include <stdio.h>
int main(){
char arrayChar[5];

for (int i=0;i<5;i++){
	arrayChar[i]=('a'+i);	
	//printf("%c",arrayChar[i]);
}
char *punteroChar;
punteroChar=&arrayChar[4];
char *punteroCharDos;
punteroCharDos=&arrayChar[4];
printf("\n%c\n",arrayChar[0]);
printf("\n%c\n",*punteroChar[1]);
printf("\n%c\n",*punteroCharDos);
printf("\n%c\n",arrayChar[4]);
printf("\n%c\n",*punteroChar);





return 0;
}
