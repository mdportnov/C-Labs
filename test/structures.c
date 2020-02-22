#include "stdio.h"

typedef struct student{
    char* name;
};

void dismissStudent(const struct student *pb){}

typedef struct sNode{
    struct sNode *next;
    int value;
} tNode;


int main(){
    tNode *p=p

    struct student student={"misha"};
    struct student *p_student;

    dismissStudent(&student); // удалили по адресу

    p_student=&student; // присвоили адрес указателю
    dismissStudent(p_student); // удалили по указателю




}