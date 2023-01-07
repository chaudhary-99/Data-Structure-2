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

void InsBeg(struct node **rear, int x)
{
    struct node *p = getnode();
    p->info = x;
    p->next = (*rear);
    (*rear) = p;
}

void InsAft(struct node **rear, int x)
{
    struct node *q;
    q = getnode();
    q->info = x;
    q->next = (*rear)->next;
    (*rear)->next = q;
}

int DelBeg(struct node **front)
{
    struct node *p;
    p =(*front);
    (*front) = (*front)->next;
    int x = p->info;
    free(p);
    return x;
}
void Enqueue(struct node **front, struct node **rear, int x)
{
    if ((*rear) == NULL)
    {
        InsBeg(&(*rear), x);
        (*front) = (*rear);
    }
    else
    {
        InsAft(&(*rear), x);
        (*rear)=(*rear)->next;
    }
}

int Dequeue(struct node **front, struct node **rear)
{
    if ((*rear) == NULL)
    {
        printf("Void Deletion\n");
        exit(1);
    }
    else
    {
        int x = DelBeg(&(*front));
        if ((*front) == NULL)
        {
            (*rear) = NULL;
        }
        return x;
    }
}

void Traverse(struct node **front, struct node** rear)
{
    struct node *p =*front;
    struct node* q=*rear;
    /*while (p!=q)
    {
        printf("%d ", p->info);
        p = p->next;
    }*/
    printf("%d\n", Dequeue(&(*front),&(*rear)));
    printf("%d\n", Dequeue(&(*front),&(*rear)));
    printf("%d\n", Dequeue(&(*front),&(*rear)));
    printf("%d\n", Dequeue(&(*front),&(*rear)));
    printf("%d\n", Dequeue(&(*front),&(*rear)));
}

int main()
{
    struct node *rear;
    struct node* front;
    rear = NULL;
    front = NULL;
    Enqueue(&front, &rear, 100);
    Enqueue(&front, &rear, 200);
    Enqueue(&front, &rear, 300);
    Enqueue(&front, &rear, 400);
    Traverse(&front,&rear);

    return 0;
}