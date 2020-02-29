#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void form(char *in, char *outDigits, char *outLetters);
char *skip(char *str);
char *copyDigits(char **from, char *to, int *nflag);
char *copyLetters(char **from, char *to, int *cflag);
char *getstr();

int main() {
    char *buf, *outDigits, *outLetters;
    buf=getstr();
    while (buf) {
        printf("Source string: \"%s\"\n", buf);

        outLetters = (char *) malloc((strlen(buf)));
        outDigits = (char *) malloc((strlen(buf)));

        form(buf, outDigits, outLetters);

        printf("Result string of nums: \"%s\" \n", outDigits);
        printf("Result string of words: \"%s\" \n", outLetters);

        free(outDigits);
        free(outLetters);
        free(buf);

        buf=getstr();
    }
}

void form(char *in, char *outDigits, char *outLetters){
    int nflag=0, cflag=0;

    while( *(in = skip(in)) ){
        if(*in >= '0' && *in <= '9'){
            if(nflag) {
                outDigits = copyDigits(&in, outDigits, &nflag);
                nflag=1;
            }
            if(!nflag)
                outDigits = copyDigits(&in, outDigits, &nflag);

        } else {
            if(cflag) {
                outLetters = copyLetters(&in, outLetters, &cflag);
                cflag=1;
            }
            if(!cflag)
                outLetters = copyLetters(&in, outLetters, &cflag);
        }
    }
    *outDigits = '\0';
    *outLetters = '\0';
}

char *copyDigits(char **from, char *to, int *nflag){
    if(*nflag==0) {
        while ((**from >= '0' && **from <= '9')) {
            *to++ = *(*from)++;
        }
        *nflag = 1;
    }else if(*nflag==1){
        *to++ = ' ';
        while ((**from >= '0' && **from <= '9')) {
            *to++ = *(*from)++;
        }
    }

    return to;
}

char *copyLetters(char **from, char *to, int *cflag){
    if(*cflag==0) {
        while ((**from >= 'A' && **from <= 'Z') || (**from >= 'a' && **from <= 'z')) {
            *to++ = *(*from)++;
        }
        *cflag=1;
    } else if(*cflag==1){
        *to++ = ' ';
        while ((**from >= 'A' && **from <= 'Z') || (**from >= 'a' && **from <= 'z')) {
            *to++ = *(*from)++;
        }
    }

    return to;
}


char *skip(char *str)
{
    while(*str && ((*str<'0' || *str>'9') && (*str<'A' || *str>'Z') && (*str<'a' || *str>'z'))){
        str++;
    }
    return str;
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