#ifndef LABS_STACK_H
#define LABS_STACK_H

#include <stdlib.h>

typedef int tData;

typedef struct sNode{
    tData value;
    struct sNode *next;
} tNode;

typedef struct {
    tNode *p_begin;
    size_t m_size;
} tStack;

void stack_push(tStack *s, tData value);
tData stack_pop(tStack *s);
tData stack_top(const tStack *s);
size_t stack_size(const tStack *s);
void stack_clear(tStack *s);
tStack stack_create();
void stack_print(const tStack *s);
int stack_is_empty(const tStack *s);

#endif //