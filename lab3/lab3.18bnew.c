#include <stdio.h>
#include <malloc.h>
#include  <string.h>

typedef struct Item {
    char c;
    struct Item *next;
}Item;

int getList(Item **pptr);
void putList(const char *msg, Item *ptr);
Item *deleteList(Item *ptr);
Item *delSpace(Item *p);
void newStrings(Item *p, Item *pptr1, Item *pptr2);

int is_digit(char a) {
    if (a >= 48 && a <= 57) {
        return 1;
    } else return 0;
}

int is_space(char a) {
    if (a == 32 || a == '\t') {
        return 1;
    } else return 0;
}

int is_alpha(char a) {
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122)) {
        return 1;
    } else return 0;
}

int getList(Item **pptr)
{
    char buf[81], *str;
    Item head = { '*', NULL };
    Item *last = &head;
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
            for (str = buf; *str != '\0'; ++str) {
                last->next = (Item *)malloc(sizeof(Item));
                last = last->next;
                last->c = *str;
            }
            last->next = NULL;
        }
        else
            scanf("%*c");
    } while (n > 0);
    *pptr = head.next;
    return rc;
}

void putList(const char *msg, Item *ptr)
{
    printf("%s: \"", msg);
    for (; ptr != NULL; ptr = ptr->next)
        printf("%c", ptr->c);
    printf("\"\n");
}

Item *deleteList(Item *ptr)
{
    Item *tmp = NULL;
    while (ptr != NULL) {
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
    return ptr;
}

Item *delSpace(Item *p) {
    Item *tmp;
    while (p && (p->c == ' ' || p->c == '\t') &&
           p->next && (p->next->c == ' ' || p->next->c == '\t')) {
        tmp = p;
        p = p->next;
        p->c = ' ';
        free(tmp);
    }
    return p;
}

void newStrings(Item *p, Item *pptr1, Item *pptr2) {
    Item head = { '*', p };
    Item head_n = { '*' };
    Item head_c = { '*' };
    Item *last_n = &head_n;
    Item *last_c = &head_c;
    Item *cur = &head;
    cur = cur->next;
    int fl = 1;

    while (cur) {

        if (cur->c == ' ' || cur->c == '\t') {
            cur = delSpace(cur);

            if (fl == 1) {
                Item *buf = cur;
                cur = cur->next;
                free(buf);
                fl = 0;
                continue;
            }

            if (cur->next == NULL) {
                free(cur);
                break;
            }

            if (last_n->c != ' ' && !is_alpha(last_n->c)) {
                last_n->next = cur;
                last_n = last_n->next;
            }

            if (last_c->c != ' ' && !is_digit(last_c->c)) {
                last_c->next = (Item *)malloc(sizeof(Item));
                last_c = last_c->next;
                last_c->c = ' ';
                last_c->next = NULL;
            }
        }
        else {
            if (fl == 1)
                fl = 0;

            if (is_digit(cur->c)) {
                last_n->next = cur;
                last_n = last_n->next;
            }
            else {
                last_c->next = cur;
                last_c = last_c->next;

            }
        }
        cur = cur->next;
    }

    last_n->next = NULL;
    last_c->next = NULL;

    putList("Result string of nums", head_n.next);
    putList("Result string of words", head_c.next);
}
int main()
{
    Item *ptr = NULL, *ptr1 = NULL, *ptr2 = NULL;
    while (puts("Enter string"), getList(&ptr)) {
        putList("Entered string", ptr);
        newStrings(ptr, ptr1, ptr2);
        ptr = deleteList(ptr);
    }
    return 0;
}