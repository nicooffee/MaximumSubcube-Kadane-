#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "kadane.h"
#include "cube.h"


int main(){
    int n=10;
    int xyz[6];
    int ***C;
    int sum,i,j,k;
    srand(time(NULL));
    C=createCube(n);
    sum=kadaneCube(C,n,&xyz[0],&xyz[1],&xyz[2],&xyz[3],&xyz[4],&xyz[5]);
    printf("\nSum: %d\n",sum);
    printf("P={");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                printf("(%d,%d,%d),",xyz[i],xyz[j+2],xyz[k+4]);
    printf("}\n");
    freeCube(C,n);
    return 0;
}

