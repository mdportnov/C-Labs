#include "stdlib.h"
#include "malloc.h"
#include "stdio.h"
#include <string.h>

#define delimiter " ,.!?\t\n" // разделитель

// Каждая строка - список char.
// Оставить слова с одинаковым
// началом и концом

typedef struct stringItem {
    char c;
    struct stringItem *next;
} stringItem;

int count_of(char s[], char ch);

// Пропуск символов до первого пробела, табуляции или 0-байта
char *skipWord(stringItem* stringItem);

// Пропуск пробелов и табуляций
char *skipSpace(char *s);

int getList(stringItem **); // ввод строки
void printList(stringItem *char_begin); // вывод строки
void deleteList(stringItem *);
void deleteTo(stringItem *, int index);

stringItem* changeList(stringItem *char_begin){
    stringItem *string=char_begin;
    int counter=0;
    char start_char=string->c;

    while(string!=NULL){
        if(string->next->c!=' '){
            string=string->next;
            counter++;
        } else if(string->next->c==' '){
            if(string->c==start_char){
                counter=0;
            } else {
                deleteTo(string, counter);
            }
        }

    }

    return string;
}


int main() {
    stringItem *st;
    while (puts("enter string.."), getList(&st)) {
        st=changeList(st);
        printList(st);
    }
}

// считать строку через список
int getList(stringItem **pptr) {
    char buf[81], *str;
    stringItem head = {'*', NULL};
    stringItem *last = &head;
    int n, rc = 1;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            deleteList(head.next);
            head.next = NULL;
            rc = 0;
            continue;
        }
        if (n > 0) {
            for (str = buf; *str != '\0'; str++) {
                last->next = (stringItem *) malloc(sizeof(stringItem));
                last = last->next;
                last->c = *str;
            }
            last->next = NULL;
        } else scanf("%*c");
    } while (n > 0);

    *pptr = head.next;
    return rc;
}

// вывод строки
void printList(stringItem *char_begin){
    stringItem *p=char_begin;
    while(p!=NULL){
        printf("%c", p->c);
        p=p->next;
    }
    printf("\n");
};

void deleteList(stringItem *p_begin){
    stringItem *p = p_begin;
    while (p != NULL) {
        stringItem *tmp;
        tmp = p;
        //шагнуть вперед !!!
        p = p->next;
        //удалить память ячейки
        free(tmp);
    }
}
void deleteTo(stringItem *p_begin, int index){
    stringItem *p = p_begin;
    for (int i = 0; i < index; ++i) {
        stringItem *tmp;
        tmp = p;
        //шагнуть вперед !!!
        p = p->next;
        //удалить память ячейки
        free(tmp);
    }
}

// Пропуск символов до первого пробела, табуляции или 0-байта
char *skipWord(struct stringItem* stringItem)
{
    int k = (int)strcspn(&stringItem->c, " "); // 1-ый совпадающий символ
    return &stringItem->c + k;
}

// Пропуск пробелов и табуляций
char *skipSpace(char *s)
{
    int k = (int)strspn(s, " "); // 1-ый несовпадающий символ
    return s + k;
}

// Кол-во вхождений ch в s
int count_of(char s[], char ch)
{
    int res = 0;
    for (; *s; ++s) {
        res += (*s == ch);
    }
    return res;
}
