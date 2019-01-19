/*---------------------------------Tarea Programación Avanzada-Ordenamiento y busqueda--------------------------------**/
/************************************************************************************************************************
    Autores   : NICOLAS IGNACIO HONORATO DROGUETT; EDUARDO ANDRÉS BALTRA ROJAS.
    Programa  : Suma máxima de un cubo.
	Proposito : Conseguir la suma máxima de un cubo de tamaño n en tiempo O(n^5).
    Fecha     : Santiago de Chile, 18 de enero de 2019
	Compilador: gcc (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0
	Standard  : C99
************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kadane.h"
#include "cube.h"


int main(){
    int n=3;
    int xyz[6];
    int ***C;
    int sum,i,j,k;
    srand(time(NULL));
    printf("\nIngrese el tamaño del cubo: ");
    scanf("%d",&n);
    C=createCube(n);
    sum=kadaneCube(C,n,&xyz[0],&xyz[1],&xyz[2],&xyz[3],&xyz[4],&xyz[5]);
    printf("\nSum: %d\n",sum);
    printf("P={");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                !(i==k && j==k && j==1)?printf("(%d,%d,%d),",xyz[i],xyz[j+2],xyz[k+4]):printf("(%d,%d,%d)",xyz[i],xyz[j+2],xyz[k+4]);
    printf("}\n");
    freeCube(C,n);
    return 0;
}

