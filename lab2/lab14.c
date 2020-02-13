#include <stdlib.h>
#include <stdio.h>

typedef struct line {
    int n;
    double *ar;
} line;

typedef struct matrix {
    int m;
    line *pt;
} matrix;


int main() {
    int m, n;
    scanf("%d", &m);

    int **matrix = (int **) malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++) {
        printf("Input quantity of elements in %d row\n", i + 1);
        scanf("%d", &n);
        matrix[i] = (int *) malloc(n * sizeof(int));
        printf("Input %d row\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("It's your matrix: \n");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < sizeof(matrix[i])/sizeof(int); j++) {
//            printf("%d", matrix[i][j]);
//        }
//        printf("\n");
//    }

    for (int i = m - 1; i > 0; i--) {
        free(matrix[i]);
    }
    free(matrix);


    return 0;
}