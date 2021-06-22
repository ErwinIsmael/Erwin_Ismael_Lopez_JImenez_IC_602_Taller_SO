//librerias
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define MAX 1000

int *sumalong(int *punteroSuma,char cadenaA[MAX], char cadenaB[MAX]);

char *colocar(char buffer[MAX], int tamano, int res[MAX]);
/*----Inicio con solicitud de argumento----*/
int main (int argc, char **argv){
if (argc > 1){
printf("\nse recibio argumentos\n");

/*-----Variables-----*/

int sk_s,sk_c,longitud_cliente,puerto;
char buf[MAX];
char cadenaA[MAX],cadenaB[MAX];
int resultado[MAX] = {0};
int *punteroSuma = resultado;
puerto=atoi(argv[1]);
//se necesita dos estructuras de tipo sockaddr
//primera guarda info de server 
//segunda guarda la del cliente
struct sockaddr_in server;
struct sockaddr_in cliente;
/* --------------------------Se llena datos del server/configurar-----------------*/
/*--FAMILIA TCP/IP--*/
server.sin_family = AF_INET;
/*----SE CONFIGURA PUERTO------*/
server.sin_port = htons(puerto);
/*---Dsponibilidad para conexion de cliente------*/
server.sin_addr.s_addr = INADDR_ANY;
bzero(&(server.sin_zero),8);

/*------APERTURA DE SOCKET*/
if((sk_s=socket(AF_INET,SOCK_STREAM,0))<0){
perror("-----------Error de apertura de socket-----------");
exit(-1);
}else{printf("\n----socket correcta apertura---\n");}

/*-----SE NOTIFICA AL CLIENTE DEL SOCKET ----*/
if (bind(sk_s,(struct sockaddr*)&server, sizeof(struct sockaddr))==-1){
printf("Error en bind() -- Verifica que el puerto no este en uso o utiliza otro puerto--\n");
exit(-1);
}else{printf("\n--Socket correcto/puerto disponible [%d]---\n",puerto);}
/*-----LISTEN ACTIVO---------*/
if(listen(sk_s,5)== -1){
printf("----Error en listen()----  \n");
exit(-1);
}else{
	printf("\n--------Listen in server-----\n");	
}
/*-----SE ACEPTA A LOS CLIENTES-----*/
while(1){
longitud_cliente = sizeof(struct sockaddr_in);
//A continuacion la llamada a accept()
if((sk_c = accept(sk_s,(struct sockaddr *)&cliente,&longitud_cliente))==-1){
printf("---------Error en accept()----------\n");
exit(-1);
}
/*----SE MANDA MENSAJE A CLIENTE DE BIENVENIDA-----*/
send(sk_c,"\n----Bienvenido a SERVER-------\n",30,0);
send(sk_c,"\n----Mandame un dato plis-------\n",30,0);

/*---SE RECIBE LOS DATOS DE CLIENTE----*/
		bzero(buf, MAX);
		printf("\n----------Se realizara una suma la cual es la siguiente----------");
		printf("\nSoy Server he recibido de CLIENTE:\n");
		recv(sk_c, buf, sizeof(buf), 0);
		printf("\n [%s] + ", buf);
		strcpy(cadenaA, buf);
		int datoA = (unsigned)strlen(cadenaA);
		bzero(buf, MAX);
		recv(sk_c, buf, sizeof(buf), 0);
		printf("[%s] = ", buf);
		//printf("\t_________\n");
		strcpy(cadenaB, buf);	
		int datoB = (unsigned)strlen(cadenaB);
		punteroSuma = sumalong(resultado, cadenaA, cadenaB);
		bzero(buf,MAX);		
		if(datoA < datoB){
			colocar(buf,datoB,punteroSuma);
			}else{
			colocar(buf,datoA,punteroSuma);
			}
	/*---SE ENVIA DATOS A CLIENTE---*/
printf("%s\nSolicitud del cliente enviada,\n-------SUMA REALIZADA SATISFACTORIAMENTE----- \n",buf);
	send(sk_c,buf,strlen(buf),0);

close(sk_c);/* Cerramos el socket cliente*/
}

close(sk_s);/*CErramos el socket server*/
}
else{
printf("----No se ingreso el puerto por parametro-----\n--Estructura [./nombre_de_ejecutable  puerto]\n");
}
return 0;
}
char *colocar(char buffer[MAX], int tamano, int res[MAX]){
int i=0,j=0,bandera;
	if ((res[i]) >= 10){
	bandera = res[i];
	buffer[0]=(bandera/10)+'0';
	buffer[1]=(bandera%10)+'0';
	tamano++;
	i=i+2;
	j++;
	}
	while(i != tamano){
	buffer[i] = res[j]+'0';
	i++;
	j++;
	}
return buffer;
}


















