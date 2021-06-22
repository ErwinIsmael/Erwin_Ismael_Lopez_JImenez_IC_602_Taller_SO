//librerias
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

/*netdb.h--Se usa para estructura hostend--*/
#define MAX 1000
/*---Se solicita los argumentos en caso de no colocarlos lo notifica--*/
int main(int argc, char *argv[])
{
if(argc > 2){

/*--variables---*/
char *ip;
int sk, numbytes,puerto;
char buf[MAX];
puerto=atoi(argv[2]);
ip=argv[1];
char cadenaA[MAX];
char cadenaB[MAX];
/*----estructuras--*/
struct hostent *he;
struct sockaddr_in server;

if((he=gethostbyname(ip))==NULL){
printf("gethostbyname() error");
exit (-1);
}

/*----Creacion de socket bueno darle lass caracteristicas o configurar---*/
if((sk=socket(AF_INET,SOCK_STREAM, 0))==.1){
printf("Socket(), error de definicion de socket\n");
exit(-1);
}else{printf("\n---Socket iniciado----\n");}

/*----Datos del server necesarios---*/
server.sin_family = AF_INET;
server.sin_port = htons(puerto);
server.sin_addr = *((struct in_addr *)he->h_addr);
/*----pasa la informacion de '*he' a 'h_addr'----*/
bzero(&(server.sin_zero),8);
/*-----Se realiza la conexion a server en caso de fallo lo notifica*/
if(connect(sk,(struct sockaddr *)&server,sizeof(struct sockaddr))==-1){
printf("connect(), error de conexion, server no encontrado\n");
exit(-1);
}else{printf("\n---conectado al server---\n");}
/*----revisa la recepcion de datos----*/
if((numbytes=recv(sk,buf,100,0)) == -1){
printf("Error en recv() \n");
exit(-1);
}
/*---solo dar la bienvenida :) --recive datos del server ----*/
buf[numbytes]='\0';
printf("          %s \n",buf);
//Datos necesarios para mandar al server (numeros para la suma)
	printf("\nIngresa el primer numero: ");
	scanf("%s", cadenaA);
	printf("Ingresa el segundo numero: ");
	scanf("%s", cadenaB);
	send(sk, cadenaA, sizeof(cadenaA), 0);
	send(sk, cadenaB, sizeof(cadenaB), 0);
	bzero(buf, MAX);
	printf("\nLa solicitud de suma mandada al Server es la sig:\n");
	printf("\n\t [%s]\n\t+", cadenaA);
	printf("\n\t [%s]\n\t_________________________________________", cadenaB);
	recv(sk, buf, sizeof(buf), 0);
	printf("\nLa Respuesta de Server a Cliente:\nResultado de la suma: %s \n", buf);
//cerrar socket
close(sk);
}
else{
printf("----No se ingreso el ip y puerto por parametro-----\n--Estructura [./nombre_de_ejecutable  direccion_IP  puerto]\n");
}
   return 0;
}




