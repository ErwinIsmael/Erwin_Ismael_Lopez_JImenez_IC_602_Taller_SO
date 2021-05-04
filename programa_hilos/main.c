#include "scheduler.h"


void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);

//se declaran los hilos pthread
void *hilo1();
void *hilo2();
void *hilo3();
void *hilo4();
void *hilo5();
void *hilo6();
void *hilo7();
void *hilo8();
void *hilo9();
int main(int argc, char const *argv[]){

	
	
	pthread_t h1,h2,h3,h4,h5,h6,h7,h8,h9;
	
	printf("\n------se crea hilo 2-----------\n");
	pthread_create(&h2,NULL,&hilo2,NULL);
	pthread_join(h2,NULL);

	printf("\n------se crea hilo 1-----------\n");
	//se crean los hilos para ello es el create	
	pthread_create(&h1,NULL,&hilo1,NULL);
	//se le da prioridad la hilo para que el hilo main no termine su ejecucion sin embargo espere a que termine el hilo
	//para ello se usa el join
	pthread_join(h1,NULL);	


	printf("\n------se crea hilo 3-----------\n");
	pthread_create(&h3,NULL,&hilo3,NULL);
	pthread_join(h3,NULL);
	printf("\n------se crea hilo 4-----------\n");
	pthread_create(&h4,NULL,&hilo4,NULL);
	pthread_join(h4,NULL);
	printf("\n------se crea hilo 5-----------\n");
	pthread_create(&h5,NULL,&hilo5,NULL);
	pthread_join(h5,NULL);
	printf("\n------se crea hilo 6-----------\n");
	pthread_create(&h6,NULL,&hilo6,NULL);
	pthread_join(h6,NULL);
	printf("\n------se crea hilo 7-----------\n");
	pthread_create(&h7,NULL,&hilo7,NULL);
	pthread_join(h7,NULL);
	printf("\n------se crea hilo 8-----------\n");
	pthread_create(&h8,NULL,&hilo8,NULL);
	pthread_join(h8,NULL);
	printf("\n------se crea hilo 9-----------\n");
	pthread_create(&h9,NULL,&hilo9,NULL);
	pthread_join(h9,NULL);
	printf("\n-------------------finaliza main-------------\n");
/*
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);
*/
	return 0;
}
//aqui le decimos al hilo las instrucciones a realizar 
void *hilo1(){
	printf("\ninicia hilo\n");
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		//<--
	fflush(stdin);
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p1);
	ejecutar_Procesos(array);
	free(array);
	free(p1);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo2 (){
	sleep(3);
	printf("\ninicia hilo\n");
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", abrir_youtube, NO_ACTIVO);
	fflush(stdin);
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p2);
	ejecutar_Procesos(array);
	free(p2);	
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}


void *hilo3 (){
	printf("\ninicia hilo\n");	
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", escribir_texto_word, ACTIVO); 	//<--
	fflush(stdin);	
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p3);
	ejecutar_Procesos(array);
	free(p3);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo4 (){
	printf("\ninicia hilo\n");
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", descargar_archivo, ACTIVO);   	//<--
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p4);
	ejecutar_Procesos(array);
	free(p4);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo5 (){
	printf("\ninicia hilo\n");	
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", subiendo_archivo, ACTIVO);
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p5);
	ejecutar_Procesos(array);
	free(p5);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo6(){
	printf("\ninicia hilo\n");	
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", compilando_programa, NO_ACTIVO);
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p6);
	ejecutar_Procesos(array);
	free(p6);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo7(){
	printf("\ninicia hilo\n");	
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", ejecutando_programa, ACTIVO);	//<--
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p7);
	ejecutar_Procesos(array);
	free(p7);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo8(){
	printf("\ninicia hilo\n");	
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", usando_terminal, ACTIVO);		//<--
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p8);
	ejecutar_Procesos(array);
	free(p8);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void *hilo9(){
	printf("\ninicia hilo\n");	
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, NO_ACTIVO);	//<--
	array_procesos *array = crear_ArrayProcesos();
	agregar_Proceso(array, *p9);
	ejecutar_Procesos(array);
	free(p9);
	printf("\nconcluye hilo\n");
	pthread_exit(NULL);
}

void reproducir_musica(void){
	printf("Reproduciendo Música\n");
}

void abrir_youtube(void){
	printf("Usando Youtube\n");
}

void escribir_texto_word(void){
	printf("Escribiendo Texto en Word\n");
}

void descargar_archivo(void){
	printf("Descargando Archivo\n");
}

void subiendo_archivo(void){
	printf("Subiendo Archivo\n");
}

void compilando_programa(void){
	printf("Compilando programa\n");
}

void ejecutando_programa(void){
	printf("Ejecutando programa\n");
}

void usando_terminal(void){
	printf("Usando la terminal\n");
}
