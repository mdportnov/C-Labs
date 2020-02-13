#include <stdlib.h>
#include <stdio.h>

typedef struct line {
    int n;
    int *arr;
} line;

typedef struct matrix {
    int m;
    line *pt;
} matrix;

int getInt(int *a);

void input(int *m, struct matrix *matrix);

void printV(int *vec, int size);

void print(matrix rm)
{
    int i,j;
    for(i=0;i<rm.m;i++)
    {
        for(j=0;j<rm.pt[i].n;j++)
        {
            printf("%d ", rm.pt[i].arr[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void erase(matrix *a)
{
    int i;
    for (i = 0; i < a->m; ++i)
        free(a->pt[i].arr);
    free(a->pt);
    a->m = 0;
    a->pt = NULL;
}

int sum_in_row(int* arr_ptr, int length)
{
    int sum =0;
    for (int i = 0; i < length; i++)
    {
        sum += *(arr_ptr + i);
    }
    return sum;
}


int main() {
    int m;
    struct matrix matrix;

    input(&m, &matrix); // ввод матрицы

    printf("It's your matrix: \n");
    print(matrix); // вывод матрицы

    printf("It's vector of your matrix: \n");

    int* vector=(int *)malloc(m*sizeof(vector));
    for (int k = 0; k < m; k++) { // заполнение вектора
        *(vector+k)=sum_in_row(matrix.pt[k].arr, matrix.pt[k].n);
    }

    printV(vector, m); // вывод вектора

    erase(&matrix); // чистим память
    return 0;
}

void printV(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
}

void input(int *m, struct matrix *matrix) {
    int n;
    getInt(m);
    (*matrix).m= (*m);
    (*matrix).pt=(line*)calloc((*m), sizeof(line));

    for (int i = 0; i < (*m); ++i) {
        printf("Input quantity of elements in %d row\n", i + 1);
        getInt(&n);
        (*matrix).pt[i].n=n;
        (*matrix).pt[i].arr=(int*)calloc(n, sizeof(int));
        printf("Input %d row\n", i + 1);

        for (int j = 0; j < n; j++) {
            getInt(&(*matrix).pt[i].arr[j]);
        }
    }
}

int getInt(int *a)
{
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c", 0);
        }
    } while (n == 0);
    return 1;
}
