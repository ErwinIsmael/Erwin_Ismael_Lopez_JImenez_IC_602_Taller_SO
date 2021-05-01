#include<stdio.h>
#include<stdlib.h>

struct informacion{
    int llegada,rafaga,tiemporespuesta,TAT,tiempoespera,np;
};
typedef struct informacion datoproceso;
int n, i,j,tiempot=0,cola[20],t=0,inicio=0,fin=0,cont=0;
datoproceso temporal;

void apilando (int q){
	cola[fin++] = q;
}
int desapilando (){
    int x;
    x = cola[inicio++];
    return x;
}
void comprobar(datoproceso a[]){
    while(a[j].llegada <= t && j < n){
        cont++;
        apilando(j++);
    }
}
void imprimir (datoproceso arr[]){
    for(i=0;i<n;i++)
    {
        arr[i].TAT = arr[i].tiemporespuesta - arr[i].llegada;
        arr[i].tiempoespera = arr[i].TAT - arr[i].rafaga;
    }
    printf("Proceso\tTiempo de llegada\tTiempo de rafaga\tTiempo de Respuesta\tTiempo de Espera\n");

    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",arr[i].np,arr[i].llegada,arr[i].rafaga,arr[i].tiemporespuesta,arr[i].tiempoespera);
    }
    printf("\n");
}
void encontrar(datoproceso a[]){
    int temp_bt[n],band=0,cont2=0;
    int act;
    j=0;
    int quantum;
    printf("\nIngrese el quantum: ");
    scanf("%d",&quantum);
    for(i=0;i<n;i++){
        temp_bt[i] = a[i].rafaga;
    }
    t = a[0].llegada;
    cont=1;
    apilando(j++);
    while(t <= tiempot){
        
        if(band==1 || cont!=0){
            if(band==0 && cont2==0){
                act=desapilando();
                cont2=0;
                band=1;
            }
            temp_bt[act]--;
            if(temp_bt[act]==0){
                t++;
                cont2=0;
                a[act].tiemporespuesta = t;
                band=0;
                cont--;
                comprobar(a);
                continue;
            }
            cont2++;
            if(cont2==quantum){
                cont2=0;
                t++;
                comprobar(a);
                apilando(act);
                band=0;
            }
            else{t++;
                comprobar(a);
            }
        }
        else{t++;
            comprobar(a);
        }
    }
    imprimir(a);
}


int main (){
    printf("\nIngrese el numero de procesos: ");
    scanf("%d",&n);
    datoproceso proceso[n];
    printf("\n");
    for(i=0;i<n;i++){
        printf("Ingrese la llegada y el rafaga del proceso %d: ",i+1);
        proceso[i].np = i+1;
        scanf("%d %d",&proceso[i].llegada,&proceso[i].rafaga);
    }
    
    for(i=0;i<n;i++)     {       for(j=i;j>=1;j--){
            if(proceso[j].llegada < proceso[j-1].llegada){
                temporal=proceso[j-1];
                proceso[j-1]=proceso[j];
                proceso[j]=temporal;
            }
            else if(proceso[j].llegada == proceso[j-1].llegada){
                if(proceso[j].rafaga < proceso[j-1].rafaga){
                    temporal=proceso[j-1];
                    proceso[j-1]=proceso[j];
                    proceso[j]=temporal;
                }
            }
        }
    }
    tiempot += proceso[0].llegada + proceso[0].rafaga;
    for(i=1;i<n;i++)     {
		if(proceso[i].llegada > tiempot)
            tiempot = proceso[i].llegada;
        tiempot += proceso[i].rafaga;
    }
    encontrar(proceso);
	system ("PAUSE");
	
    return 0;
}
