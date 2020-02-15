#include <stdio.h>
#include <math.h>
#define N 100

void bubble_sort(int* a, int n);

int getInt(int *a)
{
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]", 0);
        }
    } while (n == 0);
    return 1;
}

// Без использования указателей
int min_digit(int n) {
    if ( n < 10 )
        return n;
    else {
        int next = min_digit(n / 10);
        int last = n % 10;
        return ( last < next ) ? last : next;
    }
}
int max_digit(int n) {
    if ( n < 10 )
        return n;
    else {
        int next = max_digit(n / 10);
        int last = n % 10;
        return ( last > next ) ? last : next;
    }
}
int minmax_mult(int n) {
    int mult = 1;
    int minDigit = min_digit(n);
    int maxDigit = max_digit(n);
    for (; n; n /= 10) {
        int last = n % 10;
        if ( last == minDigit || last == maxDigit )
            mult*= last;
    }
    return mult;
}

// С использованием указателей (как просил Скитев)
int min(int n, int *count){
    int min=100000;
    int temp;
    *count=0;

    while(n>0) {
        temp = n % 10;
        if (temp < min){
            min = temp;
            (*count)=1;
        } else if (temp==min){
            (*count)++;
        }
        n=n/10;
    }
    return min;
}
int max(int n, int *count){
    int max=0;
    int temp;
    *count=0;
    while(n>0) {
        temp = n % 10;
        if (temp > max) {
            max = temp;
            (*count) = 1;
        } else if (temp == max) {
            (*count)++;
        }
        n = n / 10;
    }
    return max;
}
int minmax(int n){
    int min_count=1;
    int max_count=1;
    int minDigit = min(n, &min_count);
    int maxDigit = max(n, &max_count);

    return (int)pow(maxDigit, max_count)*(int)pow(minDigit, min_count);
}

int main() {
    int n;
    printf("Input length of sequence: \n");
    do{
        getInt(&n); // Ввёл длину последовательности
        if(n<=0){
            printf("Error. Not a natural number, repeat, please \n");
        }
    }while (n<=0);

    int nums[N]; // Объявил массив
    while(n>N){
        printf("Error");
        getInt(&n);
    }

    // Считал последовательность из потока ввода
    for (int i = 0; i < n; ) {
        int a;
        getInt(&a);
        if(a>0) {
            nums[i]=a;
            i++;
        } else printf("Please, enter natural number\n");
    }

    // Создал массив для новых значений
    int after_delete_nums[n];

    // Создал элемент для сравнения с остальными
    int max_num=minmax(nums[0]);

    printf("Max element multiply: %d \n", max_num);

    // Заполняю новый массив по условию
    int count=0;
    for (int k = 0; k < n; k++) {
        if (minmax(nums[k])<=max_num){
            after_delete_nums[count]=nums[k];
            count++;
        }
    }

    // Исходная последовательность
    printf("%s", "Your sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", nums[j]);
    }

    printf("\nNew sequence before sort: \n");
    for (int l = 0; l < count; l++) {
        printf("%d ", after_delete_nums[l]);
    }

    //Сортируем последовательность
    bubble_sort(after_delete_nums, count);

    printf("\nNew sequence after sort: \n");
    for (int l = 0; l < count; l++) {
        printf("%d ", after_delete_nums[l]);
    }
}

void bubble_sort(int* a, int n){
    for (int i = 1; i <=n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
            if (a[j] < a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    }
}
