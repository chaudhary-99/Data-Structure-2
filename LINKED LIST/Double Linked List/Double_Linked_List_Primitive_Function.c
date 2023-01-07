#include<stdio.h>
#include<stdlib.h>
struct denode{
    int info;
    struct denode* next;
    struct denode* prev;
};

struct denode* getnode(){
    struct denode *p;
    p=(struct denode*)malloc(sizeof(struct denode));
    return p;
}

void InsBeg(struct denode** dstart,int x){
    struct denode*p=getnode();
    p->next=(*dstart);
    p->info=x;
    p->prev=NULL;
    if((*dstart)!=NULL){
        (*dstart)->prev=p;
    }
    (*dstart)=p;
}

void InsEnd(struct denode** dstart,int x){
    struct denode* p=(*dstart);
    struct denode* q=getnode();
    q->info=x;
    q->next=NULL;
    if((*dstart)!=NULL){
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=q;
        q->prev=p;
    }
    else{
        q->prev=NULL;
        (*dstart)=q;
    }
}

void InsAft(struct denode**q,int x){
    if(q!=NULL){
       struct denode* p=getnode();
       struct denode* r;
       p->info=x;
       r=(*q)->next;
       r->prev=p;
       p->next=(*q)->next;
       (*q)->next=p;
       p->prev=(*q);
    }
    else{
        printf("VOID INSERTION\n");
    }
    
}

int DelBeg(struct denode**dstart){
    int x;
    return x;
}

void Traverse(struct denode**dstart){
    struct denode *p;
    p=(*dstart);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}

int main(){
    struct denode* dstart;
    dstart=NULL;
    InsBeg(&dstart,100);
    InsEnd(&dstart,200);
    InsEnd(&dstart,300);
    InsEnd(&dstart,400);
    InsBeg(&dstart,50);
    InsEnd(&dstart,500);
    Traverse(&dstart);
    return 0;
}