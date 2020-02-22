#include "stack.h"

#include <stdio.h>
#include <assert.h>

void print_list(tNode *p_begin){
    tNode *p = p_begin;
    while(p!=NULL){
        printf("%d \t", p->value);
        p=p->next;
    }
}

void delete_list(tNode *p_begin){
    tNode *p=p_begin;
    while(p!=NULL){
        tNode *tmp=p;
        p=p->next;
        free(tmp);
    }
}

void stack_push(tStack *s, tData value){
    tNode *p = (tNode *)malloc(sizeof(tNode));
    p->value=value;
    p->next=s->p_begin;

    s->p_begin=p;
    s->m_size++;
}


_Bool isEmpty(const tStack *s){
    return s->m_size==0;
}

tData stack_pop(tStack *s){
    if(isEmpty(s)) {
        printf("stack is empty");
        return NULL;
    } else {
        tNode *tmp = s->p_begin;
        tData tmp_value = tmp->value;

        s->p_begin = s->p_begin->next;

        s->m_size--;
        free(tmp);
        return tmp_value;
    }
}

tData stack_top(const tStack *s){
    if(isEmpty(s)) {
        printf("stack is empty");
        return -1;
    } else
    return s->p_begin->value;
}

size_t stack_size(const tStack *s){
    return s->m_size;
}

void stack_clear(tStack *s){
    delete_list(s->p_begin);
    s->p_begin=NULL;
    s->m_size=0;
}

tStack stack_create(){
    tStack new_stack={NULL, 0};
    return new_stack;
}

void stack_print(const tStack *s){
    print_list(s->p_begin);
}

