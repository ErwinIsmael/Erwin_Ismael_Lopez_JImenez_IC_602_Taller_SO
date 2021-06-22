#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int *sumalong(int resultado[MAX],char cadenaA[MAX], char cadenaB[MAX])
{
    
    int a[202],b[202];
    int i,j,k;

    int m,n,len;
    m=strlen(cadenaA);
    n=strlen(cadenaB);
    len = ( m > n)? m:n ;

    for ( i=0; i<m; i++)
        a[i]=cadenaA[i]-'0'; 
    for ( j=0; j<n; j++)
        b[j]=cadenaB[j]-'0'; 

    for( i=m-1,j=n-1,k=len-1; i>=0 && j>=0; i--,j--,k--)
    {
        resultado[k] = a[i] + b[j];
    }
    for( ;i>=0; i--,k--)
        resultado[k] = a[i];
    for( ;j>=0; j--,k--)
        resultado[k] = b [j];
    for( k=len-1; k>0; k--)
    {
        if( resultado[k] >9 )
        {
            resultado[k] = resultado[k]%10;
            resultado[k-1] += 1;
        }
    }
    for( k=0; k<len; k++){}
    return resultado;
}
