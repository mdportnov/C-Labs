#include <stdio.h>
#include <stdlib.h>

// Создать новую последовательность из измененных чисел
// Упорядочить её по количеству цифр

void change_digits(int num_in[], int num_out[], size_t n);

int* count_digits(int* array, size_t n);

int counter(int n);

int reverse(int number);

void bubble_sort(int* a, int n);

int main() {
    int *nums;
    int n;

    scanf("%d", &n); // Ввёл длину последовательности
    nums = (int *)malloc(n*sizeof(*nums)); // Объявил массив

    for (int i = 0; i < n; i++) {
       scanf("%d",  nums+i); // Считал последовательность из потока ввода
    }

    system("cls"); // Обновил консоль

    // Исходная последовательность
    printf("%s", "Your sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", *(nums+j));
    }
    printf("\n");

    int *n_nums=(int *)malloc(n*sizeof(n_nums)); // Создал массив для новой последовательности

    // Поменял цифры
    change_digits(nums, n_nums, n);

    // Полученная последовательность ДО сортировки
    printf("%s", "New sequence before sort:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", *(n_nums+j));
    }

    printf("\n");

    bubble_sort(n_nums, n);
    // Полученная последовательность ПОСЛЕ сортировки
    printf("%s", "New sequence after sort:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", *(n_nums+j));
    }
    return 0;
}

// Подсчёт цифр
int* count_digits(int* array, size_t n) {
    for (int i = 0; i < n; i++) {
//        printf("\n %d \n", sizeof(array)/ sizeof(*array));
        *(array+i)=counter(*(array+i));
    }
    return array;
}

// Смена цифр
void change_digits(int num_in[], int num_out[], size_t n) {
    for (int i = 0; i < n; i++) {
        num_out[i]=reverse(num_in[i]);
    }
}

int reverse(int number)
{
    int count = 1;
    while (number / count >= 10) count *= 10;

    int first = number / count;
    int last = number % 10;

    return number + (count - 1) * (last - first);
}

// Подсчёт цифр
int counter(int n)
{
    int count=0;
    if (n/10==0)
        return 1;
    else
    {
        while (n>0)
        {
            n=n/10;
            count+=1;
        }
        return count;
    }
};

void bubble_sort(int* a, int n){
    for (int i = 1; i <=n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
            if (counter(a[j]) > counter(a[j + 1]))
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    }
}
