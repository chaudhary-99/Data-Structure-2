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

void InsAft(struct node** start,int y,int x){
    if((*start)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        struct node* p;
        p=(*start);
        while(p->next!=NULL){
            if(p->info==y){
                break;
            }
            p=p->next;
        }
        struct node* q=getnode();
        q->next=p->next;
        p->next=q;
        q->info=x;
    }
}

int CycleMiddleElement(struct node** start){
    struct node* t,*r;
    t=(*start);
    r=(*start);
    while (r!=NULL&&r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t->info;

}

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
}
int main(){
    struct node* start;
    start=NULL;
    int del;
    struct node* p;
    InsBeg(&start,100);
    InsBeg(&start,200);
    InsBeg(&start,300);
    InsBeg(&start,400);
    InsEnd(&start,500);
    InsAft(&start,300,350);
    InsBeg(&start,900);
    InsBeg(&start,750);
    Traverse(&start);
    int middleElement=CycleMiddleElement(&start);
    printf("Middle Element Of Cycle %d",middleElement);

    return 0;
}