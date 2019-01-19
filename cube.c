#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cube.h"




/**
 * createCube:
 * 
 * Función que crea y retorna un arreglo tridimensional de tamaño n el cual es llenado 
 * con valores aleatorios dentro del rango [-MAX,MAX].
 */
int ***createCube(int n){
    int i,j,k;
    int ***C=(int***) calloc(n,sizeof(int**));
    for(i=0;i<n;i++){
        C[i]=(int**) calloc(n,sizeof(int*));
        for(j=0;j<n;j++){
            C[i][j]=(int*) calloc(n,sizeof(int));
            for(k=0;k<n;k++)
                C[i][j][k]=(rand()%(2*MAX+1))-MAX;
        }
    }
    return C;
}




/**
 * freeCube:
 * 
 * Función que libera la memoria del arreglo tridimensional C.
 */
void freeCube(int ***C,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            free(C[i][j]);
        free(C[i]);
    }
    free(C);
    return;
}





int ***loadCube(FILE *F,int *n){
    int i,j,k;
    int ***C=NULL;
    rewind(F);
    fscanf(F,"%d",n);
    C=(int***) calloc(*n,sizeof(int**));
    for(i=0;i<*n;i++){
        C[i]=(int**) calloc(*n,sizeof(int*));
        for(j=0;j<*n;j++){
            C[i][j]=(int*) calloc(*n,sizeof(int));
            for(k=0;k<*n;k++)
                fscanf(F,"%d",&C[i][j][k]);
        }
    }
    return C;
}