#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coef;
    int exp;
    struct node *next;
};

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void InsBeg(struct node **poly, int c, int e)
{
    struct node *p = getnode();
    p->coef = c;
    p->exp = e;
    p->next = (*poly);
    (*poly) = p;
}

void InsEnd(struct node **poly, int c, int e)
{
    if ((*poly) == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    else
    {
        struct node *p;
        p = (*poly);
        while ((p->next) != NULL)
        {
            p = p->next;
        }
        struct node *q = getnode();
        q->next = NULL;
        q->coef = c;
        q->exp = e;
        p->next = q;
    }
}

void InsAft(struct node **p, int c, int e)
{
    struct node *q;
    q = getnode();
    q->coef = c;
    q->exp = e;
    q->next = (*p)->next;
    (*p)->next = q;
}

int DelBeg(struct node **start)
{
    if ((*start) != NULL)
    {
        struct node *p;

        p = (*start)->next;

        (*start)->next = p->next;

        if ((*start)->next = (*start))
        {
            (*start) = NULL;
        }
        free(p);
    }
    else
    {
        printf("VOID DELETION\n");
    }
}

int DelEnd(struct node **start)
{
    if ((*start) != NULL)
    {

        struct node *p;
        while (p->next != *start)
        {
            p = p->next;
        }

        p->next = (*start)->next;
        if ((*start) == (*start)->next)
        {
            (*start) = NULL;
        }
        free(*start);
        (*start) = p;
    }
    else
    {
        printf("VOID DELETION\n");
    }
}

void DelAft(struct node **q)
{
    if ((*q)== NULL)
    {
        printf("VOID DELETION\n");
    }
    else
    {
        struct node *p;
        p = (*q)->next;
        (*q)->next = p->next;
        free(p);
    }
}

void OrderedIns(struct node **poly3, int x, int y)
{
    struct node *p, *q;
    p = (*poly3);
    q = NULL;
    while (p != NULL && y >= p->exp)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        InsBeg(&(*poly3), x, y);
    }
    else
        InsAft(&q, x, y);
}

void Traverse(struct node **poly)
{
    struct node *p = (*poly);
    while (p != NULL)
    {
        printf("%dx^%d ", p->coef, p->exp);
        p = p->next;
    }
    printf("\n \n");
}

void Multiplying_Polynomial(struct node **poly1, struct node **poly2)
{
    struct node *poly3;
    poly3 = NULL;
    struct node *p = (*poly1);
    
    while (p != NULL)
    {   
        struct node* q=(*poly2);
        while (q != NULL)
        {
            OrderedIns(&poly3, p->coef * q->coef, p->exp + q->exp);
            q = q->next;
        }
        p = p->next;    
    }

    struct node *z;
    z=poly3;
    while (z->next!= NULL)
    {
        if (z->exp == z->next->exp)
        {
            z->coef = z->coef + z->next->coef;
            DelAft(&z);
        }
        else{
            z=z->next;
        }
        
    }
    Traverse(&poly3);
}

int main()
{
    struct node *poly1;
    struct node *poly2;
    poly1 = NULL;
    poly2 = NULL;
    InsBeg(&poly1, 4, 7);
    InsEnd(&poly1, -2, 5);
    InsEnd(&poly1, 1, 4);
    InsEnd(&poly1, 5, 2);
    InsEnd(&poly1, 2, 0);
    Traverse(&poly1);

    InsBeg(&poly2, 8, 6);
    InsEnd(&poly2, 4, 5);
    InsEnd(&poly2, -3, 3);
    InsEnd(&poly2, 2, 2);
    InsEnd(&poly2, 7, 1);
    InsEnd(&poly2, -7, 0);
    Traverse(&poly2);
    Multiplying_Polynomial(&poly1, &poly2);
    return 0;
}