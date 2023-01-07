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


int DelBeg(struct node** start){
    if((*start)==NULL){
        printf("Linked List is empty\n");
    }
    else{
        struct node* p;
        p=(*start);
        (*start)=(*start)->next;   
        int x= p->info;
        free(p);
        return x;
    }  
}

int DelEnd(struct node** start){
    if((*start)==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        struct node* p,*q;
        q=NULL;
        p=(*start);
        while((p->next)!=NULL){
            q=p;
            p=p->next;
        }
        int x=p->info;
        q->next=NULL;
        free(p);
        return x;
    }
}
int DelAft(struct node** p){
    if((*p)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        struct node* q; 
        q=(*p)->next;
        int x= q->info;
        (*p)->next=q->next;
        free(q);
        return x;
    }
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

struct node * MiddleElement(struct node** start){
    struct node* t,*r;
    t=(*start);
    r=(*start)->next;
    while((r!=NULL)&&(r->next!=NULL)){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t;
}

int CheckPalindrome(struct node**start){
    struct node* p=MiddleElement(&(*start));
    p=p->next;
    ReverseLL(&(p));
    struct node* y;
    y=*start;
    int flag=0;
    while(p!=NULL){
        if(p->info==y->info)
        {
            p=p->next;
            y=y->next;
        }
        else{
            flag=1;
            break;
        }
    }
    return flag;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}

int main(){
    struct node* start;
    start=NULL;
    InsBeg(&start,100);
    InsEnd(&start,200);
    InsEnd(&start,300);

    InsEnd(&start,300);
    InsEnd(&start,200);
    InsEnd(&start,100);
    Traverse(&start);
    int result=CheckPalindrome(&start);
    if(result==0)
        printf("Linked List is Palindrome\n");
    else 
        printf("Linked List is not Palindrome\n");
    return 0;
}