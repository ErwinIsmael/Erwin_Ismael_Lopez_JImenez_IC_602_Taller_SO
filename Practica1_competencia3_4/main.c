#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *nombre;
	char *space;
}lista;

lista *list;

void vaciar(char temp[]);
void copiar(char temp[],int i);
void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);
int existe_archivo(char *nombre_arch);
int crear_archivo(char *nombre_arch);



int main(int argc, char *argv[]){
	int existe_arch = 0;
	int i,j;
	char aux;
	int cont=0;
	char temp[100];
	FILE *archivo;
	char delimitador[] = ",. \n";

	char arch[200];
	char cadena [100];
	char* uno;


//-----------------------verificar argumentos-------------------

	if (argc >2 && argc <=3){	
		printf("El argumento 1 es: %s \n El argumento 2 es: %s \n",argv[1],argv[2]);

		}else{
			printf("Olvido colocar los argumentos iniciales: \n 1.- ARgumento uno es el nombre de archivo existente\n");
			printf("2. Argumento dos EL nombre del archivo que se creara.\n");
			
			}
//-----------------------PARA ABRIR EL ARCHIVO INDICADO EN ARGUMENTOS--------------------	
	archivo =fopen(argv[1],"r");

	if (archivo == NULL){
		printf("\n-----------------El archivo no se pudo abrir-------------\n");
		exit(1);
	} else{
		printf("\n-------El archivo se abrio correctamente\n--------"); 

//------------------SE REALIZA LA DETECCION DE LAS PALABRAS-----------



//		fscanf(archivo, "%s", &arch);
			while(!feof(archivo)){
				printf("%s\n", arch);
				fscanf(archivo, "%s", &arch);
				cont++;
			}
			printf("\nTotal de palabras leídas: %d", cont);
			
//-------------------------------------------------------------------------------------------------------


 /*  archivo = fopen (argv[1], "r");
   if (archivo == NULL) perror ("Error opening file");
   else {
     while ( fgets (cadena , 100 , archivo) != NULL ) {
       printf ("%s", cadena);
       uno = strtok (cadena," ");
       while (uno != NULL)
       {
         printf ("%s\n",uno);
         uno = strtok (NULL, " ");
       }
     }
     fclose (archivo);
   }*/

//---------------------------------------------------
	/*	rewind(archivo);
		list = (lista*)malloc(cont*sizeof(lista));
			if (list == NULL){
				printf("No se ha podido reservar memoria \n");
				exit(1);
		
			}	
//----------------SE HACE EL RECORRIDO Y DONDE HAY ESPACIOS ESTE SEPARA LAS PALABRAS---------------------
	for(i==0; !feof(archivo);i++){
		vaciar(temp);
		aux = '0';
		for(j=0;aux != ' ';j++){
			aux = fgetc(archivo);
			if (aux != ' '){
				temp[j] = aux;
				
			}
		}
//-------------------IMPRIME EN PANTALLA LA LISTA-------------
	 	copiar(temp,i);
		printf("----->Palabra: %s \n",list[i].nombre,i);
	}
 	*/
	}
//---------------------SE COMPRUEBA LA EXISTENCIA DEL ARCHIVO ANTES DE CREAR CON NOMBRE DEL ARGUMENTO 2-----------
	do{
		
		existe_arch = existe_archivo(argv[2]);
		if(existe_arch){
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <- YA EXISTE NO SE CREO.\n",argv[2]);
			printf("---------------------------------------------------------------\n");
			break;
		}
		else{
			printf("---------------------------------------------------------------\n");
			printf("\tEl archivo -> %s <- NO EXISTE.\n", argv[2]);
			printf("---------------------------------------------------------------\n");			
			if(crear_archivo(argv[2])){
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\tEl archivo -> %s <- Fue creado EXITOSAMENTE.\n", argv[2]);	
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

				archivo = fopen(argv[2],"w");

				printf("\nPALABRAS EN EL NUEVO ARCHIVO\n");
				for (i=0;i<=cont;i++){
					fprintf(archivo,"%s",arch);
				
				} 
				
			}
			else{
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
				printf("\tEl archivo -> %s <- NO pudo crearse.\n", argv[2]);			
				printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
		}
	}while(existe_arch);

return 0;
}


int existe_archivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 0;
	// Con r abre un archivo para lectura.
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}

int crear_archivo(char *nombre_arch){
	int creado = 0;
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "w");
	if( ptrArchivo == NULL ){
		// con w crea un archivo para escritura. Si el archivo ya existe, descarta el contenido actual.
		printf("----> El archivo -> %s <- no pudo crearse (abrir; uso de w).\n", nombre_arch);
	}	
	else{
		creado = 1;
		printf("----> Archivo -> %s <- Creado (abierto; uso de w).\n", nombre_arch);
		cerrar_archivo(ptrArchivo, nombre_arch);
	}
	return creado;
}



void vaciar(char temp[]){

	int i;
	for(i= 0;i<50;i++){
		temp[i] ='\0';	
	}

}

void copiar(char temp[],int i){
	int N = strlen(temp)+1;
	list[i].nombre = (char*) malloc(N*sizeof(char));
	if(list[i].nombre ==NULL){
		printf("No se ha podido reservar memoria \n");
		exit(1);
	}
	strcpy(list[i].nombre, temp);
}

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);
	printf("----> Archivo -> %s <- Cerrado Correctamente.\n", nombre_arch);
}



