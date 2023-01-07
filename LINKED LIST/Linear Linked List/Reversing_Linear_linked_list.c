#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};


struct node* getnode(){
   struct node* p;
   p=(struct node*)malloc(sizeof(struct node));
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
        printf("LINKED LIST IS EMPTY\n");
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

void InsAft(struct node** p,int x){
    struct node* q;
    q=getnode();
    q->info=x;
    q->next=(*p)->next;
    (*p)->next=q;
}

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}

void ReverseLL(struct node** start){
    struct node* p;
    struct node *c;
    struct node *n;
    p=NULL;
    c=(*start);
    n=(*start)->next;
    while(c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL){
            n=n->next;
        } 
    }
    (*start)=p;
    
    
}


int main(){
    struct node* start;
    start=NULL;
    InsBeg(&start,100);
    InsEnd(&start,200);
    InsEnd(&start,300);
    InsEnd(&start,400);

    Traverse(&start);

    ReverseLL(&start);
    Traverse(&start);
    return 0; 
}