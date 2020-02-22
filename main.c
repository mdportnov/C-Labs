#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test/stack.c"
#include "test/stack.h"


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

// Пропуск пробелов и табуляций
char *skipSpace(char *s)
{
    int k = (int)strspn(s, " "); // 1-ый несовпадающий символ
    return s + k;
}

char *copyWord(char *from, char *to)
{
    int k = (int)strcspn(from, " "); // длина слова
    strncat(to, from, k);
    to += k;
    *to++ = ' ';
    *to = '\0';
    return to;
}


int main() {

//    char* word=(char*)malloc(sizeof(char));
//    word=getstr();
//    char* newWord=(char *)malloc(strlen(word)+1);
//    copyWord(word, newWord);
//    printf("%s", newWord);

    return 0;
}
