#include <stdio.h>
#include <stdlib.h>

#define ROW_NUM 10
#define COL_NUM 5
#define SIZE 10

int main() {

    float  **p=NULL;
    unsigned c;

    p=(float**)malloc(ROW_NUM*sizeof(float*));
    for (c = 0; c < ROW_NUM; c++) {
        p[c]=(float*)malloc(COL_NUM * sizeof(float));
    }

    for (c = 0; c < ROW_NUM; ++c) {
        free(p[c]);
    }
    free(p);



    int **A;
    int i, j;
    A = (int**) malloc(SIZE * sizeof(int*));

    for (i = 0; i < SIZE; i++) {
        A[i] = (int*) malloc((i + 1) * sizeof(int));
    }

    for (i = 0; i < SIZE; i++) {
        for (j = i; j > 0; j--) {
            A[i][j] = i * j;
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = i; j > 0; j--) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (i = SIZE-1; i > 0; i--) {
        free(A[i]);
    }
    free(A);
    return 0;
}
