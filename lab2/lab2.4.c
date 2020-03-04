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

void pos_and_neg_in_row(int *arr, int n, int *pos, int *neg) {
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) > 0) (*pos)++;
        if (*(arr + i) < 0) (*neg)++;
    }
}

int getInt(int *a);

int getNaturalInt(int *a);

void input(int *m, struct matrix *matrix);

void create_new_matrix(matrix *matrix, struct matrix *newMatrix, int pos_row, int neg_row);

void print(matrix *rm) {
    int i, j;

    line *m_ptr = rm->pt;
    int *ptr;

    for (i = 0; i < rm->m; i++) {
        ptr = m_ptr->arr;
        for (j = 0; j < m_ptr->n; j++) {
            printf("%d ", *(ptr++));
        }
        m_ptr++;
        printf("\n");
    }
    printf("\n");
}

void printV(int *vec, int size) {
    printf("\nIt's vector: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", (int) vec[i]);
    }
    printf("\n");
}

void erase(matrix *a) {
    int i;
    for (i = 0; i < a->m; ++i)
        free(a->pt[i].arr);
    free(a->pt);
    a->m = 0;
    a->pt = NULL;
}

int main() {
    int m;
    struct matrix matrix;
    input(&m, &matrix); // ввод матрицы
    printf("It's your matrix: \n");
    print(&matrix); // вывод матрицы

    line *m_ptr = matrix.pt;

    int pos = 0, neg = 0, pos_max = 0, neg_max = 0; // Кол-во положительных и отрицательных чисел в строке, а так же максимальные
    int pos_row = 0, neg_row = 0; // Индексы строк, которые будем менять

    for (int k = 0; k < m; k++, m_ptr++) {
        pos_and_neg_in_row(m_ptr->arr, m_ptr->n, &pos, &neg); // Счётчики примут значения по k-ой строке
        if (pos > pos_max) {
            pos_max = pos;
            pos_row = k;
        }
        if (neg > neg_max) {
            neg_max = neg;
            neg_row = k;
        }

        pos = 0;
        neg = 0;
    }

    // Вывод строк, которые должны будут "свапнуться" с первой и последней, соответственно
    printf("%d line is the highest number of positive numbers \n", pos_row + 1);
    printf("%d line is the highest number of negative numbers \n", neg_row + 1);

    // Создаем новую матрицу
    struct matrix newMatrix;

    create_new_matrix(&matrix, &newMatrix, pos_row, neg_row);

    printf("\nIt's your new matrix: \n");
    print(&newMatrix);

    erase(&matrix); // Чистим память
    erase(&newMatrix);
    return 0;
}

void create_new_matrix(matrix *matrix, struct matrix *newMatrix, int pos_row, int neg_row) {
    (*newMatrix).m = matrix->m; // Выделил высоту новой матрицы
    (*newMatrix).pt = (line *) calloc(newMatrix->m, sizeof(line));

    // Выделение длины новой последней строчки, в которой будет старая NEG_ROW
    (*newMatrix).pt[matrix->m - 1].n = (int) matrix->pt[neg_row].n;
    (*newMatrix).pt[matrix->m - 1].arr = (int *) matrix->pt[neg_row].arr;

    // Выделение длины новой строчки с индексом NEG_ROW ???
    (*newMatrix).pt[neg_row].n = (int) matrix->pt[matrix->m - 1].n;
    (*newMatrix).pt[neg_row].arr = (int *) matrix->pt[matrix->m - 1].arr;

    // Выделение длины новой первой строчки, в которой будет старая POS_ROW
    (*newMatrix).pt[0].n = (int) matrix->pt[pos_row].n;
    (*newMatrix).pt[0].arr = (int *) matrix->pt[pos_row].arr;

    // Выделение длины новой строчки с индексом POS_ROW
    (*newMatrix).pt[pos_row].n = (int) matrix->pt[0].n;
    (*newMatrix).pt[pos_row].arr = (int *) matrix->pt[0].arr;

    int index = 0;
    for (int i = 0; i < matrix->m; i++) {
        if ((i != neg_row) && (i != pos_row) && i != 0 && i != matrix->m) {
            index++;
            (*newMatrix).pt[i].n = (int) matrix->pt[i].n;
            (*newMatrix).pt[i].arr = (int *) matrix->pt[i].arr;
        }
    }

    // Вывод главных строчек (с pos и neg)
    printV(matrix->pt[pos_row].arr, matrix->pt[pos_row].n);
    printV(matrix->pt[neg_row].arr, matrix->pt[neg_row].n);

}

void input(int *m, struct matrix *matrix) {
    printf("Input quantity of rows: \n");
    int n;
    getNaturalInt(m);
    (*matrix).m = (*m);
    (*matrix).pt = (line *) calloc((*m), sizeof(line));

    for (int i = 0; i < (*m); ++i) {
        printf("Input quantity of elements in %d row\n", i + 1);
        getNaturalInt(&n);
        (*matrix).pt[i].n = n;
        (*matrix).pt[i].arr = (int *) calloc(n, sizeof(int));
        printf("Input %d row\n", i + 1);

        for (int j = 0; j < n; j++) {
            getInt(&(*matrix).pt[i].arr[j]);
        }
    }
}

int getInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]", 0);
        }
    } while (n == 0);
    return 1;
}

int getNaturalInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0 || *a <= 0) {
            printf("%s\n", "Error! Please, repeat your input: ");
            scanf("%*[^\n]", 0);
        }
    } while (n == 0 || *a <= 0);
    return 1;
}