#include <stdio.h>
#include <stdlib.h>

void count_digits(int *array, int *arr, size_t n);

int counter(int n);

void bubble_sort(int *a, int n);

int rebuild(int x);

int getInt(int *a) {
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*c", 0);
        }
    } while (n == 0);
    return 1;
}

int main() {
    int n;
    getInt(&n); // Ввёл длину последовательности
    int nums[n]; // Объявил массив

    for (int i = 0; i < n; i++) {
        getInt(&nums[i]); // Считал последовательность из потока ввода
    }


    // Исходная последовательность
    printf("%s", "Source sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", nums[j]);
    }
    printf("\n");

    // Создал массив для последовательности количества цифр
    int digit_nums[n];
    count_digits(nums, digit_nums, n);

    for (int k = 0; k < n; ++k) { // Перезаполняю массив измененными значениями
        nums[k] = rebuild(nums[k]);
    }

    //Сортируем обе последовательности
    bubble_sort(nums, n);

    printf("\n");

    // Вторая полученная последовательность
    printf("%s", "New sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", nums[j]);
    }
    return 0;
}

int rebuild(int x) {
    int n = x, m = 0;
    int p = 1;
    x ^= x;
    do {
        m = n % 10; /* цифра */
        m = (m != 0) ? --m : 9;
        x += m * p;
        p *= 10;
        n /= 10; /* следующий разряд*/
    } while (n);

    return x;
}

// Подсчёт цифр на массив
void count_digits(int *array, int *arr, size_t n) {
//    arr=(int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) {
        *(arr + i) = counter(*(array + i));
    }
}

// Подсчёт цифр
int counter(int n) {
    int count = 0;
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

void bubble_sort(int *a, int n) {
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < n - i; j++)
            if (a[j] < a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    }
}
