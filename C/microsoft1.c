/*
Write a code to extract individual blocks from a given matrix....
Eg: if we have a 4x4 matrix you need to extract 2x2 independent 
matrices and store them in 4 different arrays...

Given matrix:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
For the above matrix the output should be as follows..
Array1: 1 2 5 6
Array2: 3 4 7 8
Array3: 9 10 13 14
Array4: 11 12 15 16


*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N=8; // N*N matrix

int main() {
    int i,j;
    int b[4][(N*N)/4];
    int c[2*N][4];
    int a[N][N];
    int dev=N/2;
    srand(time(NULL));

//creating and printing input
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            a[i][j]=rand()%100;
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }

/* actaul copying done here */
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            b[((i/dev)*2)+(j/dev)][(j%dev) + dev*(i%dev)]=a[i][j];
            c[((i/2)*dev)+j/2][(i%2)*2 + j%2]=a[i][j];
        }
    }

//printing output1
    for(i=0;i<;4;i++)
    {
        for(j=0;j<(N*N)/4;j++)
        {
            printf("%2d ",b[i][j]);
        }
        printf("\n");
    }

//printing out other output
    for(i=0;i<;2*N;i++)
    {
        for(j=0;j<;4;j++)
        {
            printf("%2d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
