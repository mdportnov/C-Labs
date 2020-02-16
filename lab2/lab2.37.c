#include <stdlib.h>
#include <stdio.h>

//  Из входного потока вводится непрямоугольная матрица целых чисел
//  [aij], i = 1, …, m, j = 1, …, ni.
//  Значения m и ni заранее не известны и вводятся из входного потока.
//
//  Сформировать новую матрицу, поместив в ее i-ую строку те элементы из i-ой строки исходной матрицы,
//        количество цифр в записи которых превышает
//        среднее количество цифр в записи всех элементов данной строки матрицы.
//
//  В дополнительных функциях доступ к элементам массивов реализовать с помощью указателей.
//  Исходную и полученную матрицы вывести в выходной поток с необходимыми комментариями.

typedef struct line {
    int n;
    int *arr;
} line;

typedef struct matrix {
    int m;
    line *pt;
} matrix;

// Подсчёт цифр в числе
int counter(int n) {
    int count = 0;
    if (n < 0) n = -n;
    if (n / 10 == 0)
        return 1;
    else {
        while (n > 0) {
            n = n / 10;
            count += 1;
        }
        return count;
    }
}

double average_in_row(int *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += counter(*(arr + i));
    }
    return sum / n;
}

int getInt(int *a);

int getNaturalInt(int *a);

void input(int *m, struct matrix *matrix);

void printV(double *vec, int size);

void printNV(double *vec, int size);

void create_new_matrix(struct matrix *matrix, struct matrix *newMatrix,
                       double *vector);

void print(matrix *rm) {
    int i, j;
    for (i = 0; i < rm->m; i++) {
        for (j = 0; j < rm->pt[i].n; j++) {
            printf("%d ", rm->pt[i].arr[j]);
        }
        printf("\n");
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

    double *vector = (double *) malloc(m * sizeof(vector));

    for (int k = 0; k < m; k++) { // заполнение вектора
        *(vector + k) = average_in_row(matrix.pt[k].arr, matrix.pt[k].n);
    }

    printV(vector, m); // вывод вектора средних значений по строкам

    // Создаем новую матрицу
    struct matrix newMatrix;

    create_new_matrix(&matrix, &newMatrix, vector);

    printf("It's your new matrix: \n");
    print(&newMatrix);

    erase(&matrix); // чистим память
    return 0;
}


void printV(double *vec, int size) {
    printf("\nIt's vector of average value in row of your matrix: \n");
    for (int i = 0; i < size; i++) {
        printf("%.1f ", vec[i]);
    }
    printf("\n");
}

void printNV(double *vec, int size) {
    printf("\nIt's vector of numbers quantity in row of your matrix: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", (int) vec[i]);
    }
    printf("\n");
}

void create_new_matrix(matrix *matrix, struct matrix *newMatrix, double *vector) {
    (*newMatrix).m = matrix->m;
    (*newMatrix).pt = (line *) calloc(newMatrix->m, sizeof(line));

    double *rows_length = (double *) malloc((newMatrix->m) * sizeof(double)); // Массив длин строк новой матрицы

    for (int k = 0; k < newMatrix->m; ++k) {
        *(rows_length + k) = 0;
    }

    for (int i = 0; i < matrix->m; i++) {
        for (int j = 0; j < matrix->pt[i].n; j++) {
            if ((double) counter(matrix->pt[i].arr[j]) >= *(vector + i)) {
                (*(rows_length + i))++;
            }
        }
    }

    printNV(rows_length, newMatrix->m); // Вывод вектора длин строк новых матриц
    printf("\n");

    int index = 0;
    for (int i = 0; i < (newMatrix->m); i++) { // Перебор строк
        (*newMatrix).pt[i].n = (int) rows_length[i];
        (*newMatrix).pt[i].arr = (int *) calloc((int) rows_length[i], sizeof(int));
        index = 0;

        for (int j = 0; j < matrix->pt[i].n; j++) { // Перебор конкретной строки
            if ((double) counter(matrix->pt[i].arr[j]) >= *(vector + i)) {
                newMatrix->pt[i].arr[index] = matrix->pt[i].arr[j];
                index++;
            }
        }
    }
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
