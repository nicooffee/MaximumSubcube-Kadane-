#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kadane.h"




/**
 * kadaneCube:
 * 
 * Función que retorna la suma máxima dentro de un cubo C, como también los límites
 * del subcubo que dan como resultado a dicha suma. 
 */
int kadaneCube(int ***C,int n,int *xa,int *xb,int *ya,int *yb,int *za,int *zb){
    int i,j,k,l;
    int sumMax=-2147483648,sumAux,xaAux,xbAux,yaAux,ybAux;
    int **temp;
    for(i=0;i<n;i++){
        temp=(int**) calloc(n,sizeof(int*));
        for(k=0;k<n;k++)
            temp[k]=(int*) calloc(n,sizeof(int));
        for(j=i;j<n;j++){
            for(k=0;k<n;k++)
                for(l=0;l<n;l++)
                    temp[k][l]+=C[k][l][j];
            sumAux=kadaneMatrix(temp,n,&xaAux,&xbAux,&yaAux,&ybAux);
            if(sumMax<sumAux){
                sumMax=sumAux;
                *xa=xaAux;
                *xb=xbAux;
                *ya=yaAux;
                *yb=ybAux;
                *za=i;
                *zb=j;
            }
        }
        for(k=0;k<n;k++)
            free(temp[k]);
        free(temp);
    }
    return sumMax;
}




/**
 * kadaneMatrix:
 * 
 * Función que retorna la suma máxima dentro de una matriz M. Además, la
 * función retorna los límites del subrectángulo que dan resultado a la suma
 * máxima dentro de M.
 */
int kadaneMatrix(int **M,int n,int *xa,int *xb,int *ya,int *yb){
    int i,j,k;
    int sumMax=-2147483648,sumAux,xaAux=0,xbAux=0;
    int *temp;
    for(i=0;i<n;i++){
        temp=(int*) calloc(n,sizeof(int));
        for(j=i;j<n;j++){
            for(k=0;k<n;k++)
                temp[k]+=M[k][j];
            sumAux=kadaneArray(temp,n,&xaAux,&xbAux);
            if(sumAux>sumMax){
                sumMax=sumAux;
                *xa=xaAux;
                *xb=xbAux;
                *ya=i;
                *yb=j;
            }
        }
        free(temp);
    }
    return sumMax;
}




/**
 * kadaneArray: 
 * 
 * Función que retorna la suma máxima dentro de un arreglo A. Como también los límites
 * del subarreglo que dan resultado a la suma. 
 */
int kadaneArray(int *A,int n, int *xa, int* xb){
    int sumaLocal,sumaTotal;
    int i,aux=0;
    sumaLocal=sumaTotal=A[0];
    *xa=*xb=0;
    for(i=1;i<n;i++){
        if(A[i]>sumaLocal+A[i]){
            sumaLocal=A[i];
            aux=i;
        }
        else
            sumaLocal+=A[i];
        if(sumaTotal<sumaLocal){
            sumaTotal=sumaLocal;
            *xa=aux;
            *xb=i;
        }
    }
    return sumaTotal;
}