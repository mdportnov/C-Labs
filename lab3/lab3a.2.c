#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

char *getstr();

// Пропуск символов до первого пробела, табуляции или 0-байта
char *skipWord(char *s)
{
    int k = (int)strcspn(s, " \t"); // 1-ый совпадающий символ
    return s + k;
}

// Пропуск пробелов и табуляций
char *skipSpace(char *s)
{
    int k = (int)strspn(s, " \t"); // 1-ый несовпадающий символ
    return s + k;
}

char *copyWord(char *from, char *to)
{
    int k = (int)strcspn(from, " \t"); // длина слова
    strncat(to, from, k);
    to += k;
    *to++ = ' ';
    *to = '\0';
    return to;
}


char *reorg(char *s)
{
// Выделяем память под выходные данные
    char *p = (char *)malloc(strlen(s) + 1);
    char *tmp = p;
    int fl = 0; // для выбора каждого второго слова
    *tmp = '\0'; // нуль ограниченная рез. строка

    // пропуск пробелов
    while (*(s = skipSpace(s))){
        if (fl) // нужное слово
            tmp = copyWord(s, tmp);
        fl = !fl;
        s = skipWord(s); // пропускаем слово в исходной строке
    }
    // удаление хвостого пробела
    if (p != tmp)
        *--tmp = '\0';
    p = (char *)realloc(p, strlen(p) + 1);

    return p;
}



int main(){
    char *str=(char*)malloc(sizeof(char));
    char *p=(char*)malloc(sizeof(char));

    while (str=getstr(str)) {
        printf("Source string: \"%s\"\n", str);
        p = reorg(str);
        printf("Result string: \"%s\"\n", p);
        free(str);
        free(p);
    }
    puts("That's all. Bye!");

    return 0;
}

char* getstr()
{
    char *ptr=(char*)malloc(1);
    char buf[81];
    int n, len=0;
    *ptr='\0';

    do{
        n=scanf("%80[^\n]", buf);
        if(n<0){
            free(ptr);
            ptr=NULL;
            continue;
        }
        if(n==0) scanf("%*c", 0);
        else{
            len+=strlen(buf);
            ptr=(char*)realloc(ptr, len+1);
            strncat(ptr, buf, len);
        }
    } while (n>0);
    return ptr;
}
