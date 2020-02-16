#include <stdio.h>
#include <stdlib.h>

void count_digits(int* array,int* arr, size_t n);

void count_sums(int* array, int* arr, size_t n);

int counter(int n);

void bubble_sort(int* a, int n);

int digit_sum(int n);

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

int main() {
    int n;
    getInt(&n); // Ввёл длину последовательности
//    scanf("%d", &n); // Ввёл длину последовательности
    int nums[n]; // Объявил массив

    for (int i = 0; i < n; i++) {
//       scanf("%d",  &nums[i]); // Считал последовательность из потока ввода
       getInt(&nums[i]); // Считал последовательность из потока ввода
    }


    // Исходная последовательность
    printf("%s", "Your sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", nums[j]);
    }
    printf("\n");

    // Создал массив для последовательности количества цифр
    int digit_nums[n];
    count_digits(nums, digit_nums, n);

    // Создал массив для последовательности суммы нечетных цифр
    int sum_nums[n];
    count_sums(nums, sum_nums, n);


    //Сортируем обе последовательности
    bubble_sort(sum_nums, n);
    bubble_sort(digit_nums, n);

    // Первая полученная последовательность
    printf("%s", "Numeric sequence :\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", digit_nums[j]);
    }

    printf("\n");

    // Вторая полученная последовательность
    printf("%s", "Sum sequence:\n");
    for (int j = 0; j < n; j++) {
        printf("%d  ", sum_nums[j]);
    }
    return 0;
}

// Подсчёт цифр на массив
void count_digits(int* array, int* arr, size_t n) {
//    arr=(int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) {
        *(arr+i)=counter(*(array+i));
    }

}


void count_sums(int* array, int* arr, size_t n) {
//    *arr=(int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) {
        *(arr+i)=digit_sum(*(array+i));
    }
}

// Подсчёт суммы нечетных цифр
int digit_sum(int n){
    int i, s1=0, s2=0, k=0, n2;
    while(n != 0)
    {
        n2 = n; n/=10; n2%=10;
        if(k % 2 == 0) s1+=n2; else s2+=n2;
        k++;
    }
    if(k % 2 == 0) return s2; else return s1;

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
}

void bubble_sort(int* a, int n){
    for (int i = 1; i <=n-1; i++)
    {
        for (int j = 0; j < n-i; j++)
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    }
}
