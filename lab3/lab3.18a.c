#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char *getstr();

void reorgStr(const char *s, char *out1, char *out2);

char *deleteSpaces(char *str) {
    char *res = (char *) malloc(sizeof(char) * strlen(str));
    int j = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            if (j == 0) continue;
            if (str[i + 1] == ' ') continue;
        }
        res[j] = str[i];
        j++;
    }
    i = (int) strlen(res);
    if (res[i - 1] == ' ')
        res[i - 1] = '\0';
    return res;
}

char *deleteTabs(char *str){
    char *res = (char *) malloc(sizeof(char) * strlen(str));

    int i;
    for (i = 0; i < strlen(str); i++) {
       if(str[i]=='\t'){
           res[i]=' ';
       } else res[i]=str[i];
    }

    if (res[strlen(res)-1] == '\t')
        res[strlen(res)-1] = '\0';

    return res;
}

int main() {
    char *str, *out1, *out2;

    str = getstr();
    while (str) {
        printf("Source string: \"%s\"\n", str);

        out1 = (char *) malloc(strlen(str) * sizeof(char));
        out2 = (char *) malloc(strlen(str) * sizeof(char));

        reorgStr(str, out1, out2);

        out1=deleteTabs(out1);
        out1=deleteSpaces(out1);

        out2=deleteTabs(out2);
        out2=deleteSpaces(out2);


        printf("String of nums: \"%s\"\n", out1);
        printf("String of words: \"%s\"\n", out2);

        free(str);
        free(out1);
        free(out2);
        str = getstr(str);
    }
    puts("That's all. Bye!");

    return 0;
}

int is_digit(char a){
    if(a>=48 && a<=57){
        return 1;
    } else return 0;
}

int is_space(char a){
    if(a==32 || a=='\t'){
        return 1;
    } else return 0;
}

int is_alpha(char a){
    if((a>=65 && a<=90) || (a>=97 && a<=122)){
        return 1;
    } else return 0;
}

void reorgStr(const char *str, char *out1, char *out2) {
    int num_index = 0, char_index = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (is_digit(*(str + i))) {
            *(out1 + (num_index++)) = *(str + i);
            if (is_space(*(str + i + 1)) || is_alpha(*(str + i + 1))) {
                *(out1 + num_index++) = ' ';
            }

        } else if (is_alpha(*(str + i))) {
            *(out2 + (char_index++)) = *(str + i);
            if (is_space(*(str + i + 1)) || is_digit(*(str + i + 1))) {
                *(out2 + char_index++) = ' ';
            }
        }
    }

    if(!char_index) {
//        out2 = (char *) realloc(out2, 9 * sizeof(char));
        strcpy(out2, "no chars");
    }
    if(!num_index) {
//        out1 = (char *) realloc(out1, 8 * sizeof(char));
        strcpy(out1, "no nums");
    }

}

char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';

    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0) scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strncat(ptr, buf, len);
        }
    } while (n > 0);
    return ptr;
}
