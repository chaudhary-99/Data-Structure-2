#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};

struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void InsBeg(struct node **start, int x)
{
    struct node *p = getnode();
    p->info = x;
    p->next = (*start);
    (*start) = p;
}

void InsEnd(struct node **start, int x)
{
    if ((*start) == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
    }
    else
    {
        struct node *p;
        p = (*start);
        while ((p->next) != NULL)
        {
            p = p->next;
        }
        struct node *q = getnode();
        q->next = NULL;
        q->info = x;
        p->next = q;
    }
}

void InsAft(struct node **p, int x)
{
    struct node *q;
    q = getnode();
    q->info = x;
    q->next = (*p)->next;
    (*p)->next = q;
}

void OrderedIns(struct node **start, int x)
{
    struct node *p, *q;
    p = (*start);
    q = NULL;
    while (p != NULL && x >= p->info)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        InsBeg(&(*start), x);
    }
    else
        InsAft(&q, x);
}
int DelBeg(struct node **start)
{
    if ((*start) == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        struct node *p;
        p = (*start);
        (*start) = (*start)->next;
        int x = p->info;
        free(p);
        return x;
    }
}

void PQInsertion(struct node **start, int y, int x)
{
    if ((*start) == NULL)
    {
        printf("INVALID NODE\n");
    }
    else
    {
        struct node *p;
        p = (*start);
        while (p->next != NULL)
        {
            if (p->info == y)
            {
                break;
            }
            p = p->next;
        }
        struct node *q = getnode();
        q->next = p->next;
        p->next = q;
        q->info = x;
    }
}

int PQDeletion(struct node **start)
{
    if ((*start) == NULL)
    {
        printf("Linked List is empty\n");
    }
    else
    {
        int x = Delbeg(&(*start));
        (*start) = (*start)->next;
        return x;
    }
}

void Traverse(struct node **start)
{
    struct node *p = (*start);
    while (p != NULL)
    {
        printf("%d\n", p->info);
        p = p->next;
    }
}
int main()
{
    struct node *start;
    start = NULL;
    int del;
    struct node *p;

    InsBeg(&start, 100);
    InsBeg(&start, 200);
    InsBeg(&start, 300);
    InsBeg(&start, 400);

    PQInsertion(&start, 200, 200);
    PQInsertion(&start, 400, 500);
    PQInsertion(&start, 500, 600);
    PQInsertion(&start, 300, 300);
    Traverse(&start);
    printf("\n");

    del = PQDeletion(&start);
    printf("Deleted_Element from Starting %d\n", del);
    Traverse(&start);
    printf("\n");

    return 0;
}