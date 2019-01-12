#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cube.h"





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