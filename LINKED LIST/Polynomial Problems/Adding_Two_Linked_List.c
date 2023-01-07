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

void AddingLL(struct node**start1,struct node**start2){
    ReverseLL(&(*start1));
    ReverseLL(&(*start2));
    struct node* p,*q;
    struct node* start3;
    p=(*start1);
    q=(*start2);
    int carry=0;
    int sum;
    int total;
    while(p!=NULL&&q!=NULL){
        total=p->info+q->info+carry;
        sum=total%10;
        carry=total/10;
        p=p->next;
        q=q->next;
        InsEnd(&start3,sum);
    }
    while(p!=NULL){
        total=p->info+carry;
        sum=total%10;
        carry=total/10;
        p=p->next;
        InsEnd(&start3,sum);
    }
    while(q!=NULL){
        total=q->info+carry;
        sum=total%10;
        carry=total/10;
        q=q->next;
        InsEnd(&start3,sum);
        if(carry>0){
            InsEnd(&start3,carry);
        }
        ReverseLL(&start3);
        Traverse(&start3);
    }
    Traverse(&start3);
}
int main(){
    struct node* start1;
    struct node* start2;
    start1=NULL;
    start2=NULL;

    InsBeg(&start1,1);
    InsEnd(&start1,2);
    InsEnd(&start1,5);
    Traverse(&start1);

    InsBeg(&start2,6);
    InsEnd(&start2,4);
    Traverse(&start2);
    AddingLL(&start1,&start2);
    return 0;
}