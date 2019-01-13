#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cube.h"
#include "kadane.h"

int main(){
    FILE *F=fopen("prueba.txt","r");
    int n,i,j,k;
    int ***C=loadCube(F,&n);
    int sum;
    int xyz[6];
    srand(time(NULL));
    sum=kadaneCube(C,n,&xyz[0],&xyz[1],&xyz[2],&xyz[3],&xyz[4],&xyz[5]);
    printf("\nSum: %d\n",sum);
    printf("P={");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                printf("(%d,%d,%d),",xyz[i],xyz[j+2],xyz[k+4]);
    printf("}\n");
    freeCube(C,n);
}