#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
struct node *Ht[15];
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void InsBeg(struct node** start,int x){
   struct node* p=getnode();
   p->info=x;
   p->next=(*start);
   (*start)=p;
}

void InsEnd(struct node** start,int x){
    if((*start)==NULL){
        InsBeg(&(*start),x);
    }
    else{
        struct node* p;
        p=(*start);
        while((p->next)!=NULL){
            p=p->next;
        }
        struct node* q=getnode();
        q->next=NULL;
        q->info=x;
        p->next=q;
    }
}

void Traverse(struct node **start)
{
    struct node *p = (*start);
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}
int main()
{
    int n;
     cout<<"How many data element are to be stored\n";
    cin>>n;
    int x, r;
    for (int i = 0; i <= 14; i++)
    {
        Ht[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        r = x % 10;
        InsEnd(&Ht[r], x);
    }
    for (int i = 0; i < 15; i++)
    {

        cout << i << ":";
        Traverse(&Ht[i]);

        cout << endl;
    }
    return 0;
}
