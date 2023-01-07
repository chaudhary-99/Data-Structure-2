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

void InsBeg1(struct node** start1,int x){
   struct node* p=getnode();
   p->info=x;
   p->next=(*start1);
   (*start1)=p;
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

void InsEnd1(struct node** start1,int x){
    if((*start1)==NULL){
        printf("LINKED LIST IS EMPTY\n");
    }
    else{
        struct node* p;
        p=(*start1);
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

void InsAft1(struct node** start1,int y,int x){
    if((*start1)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        struct node* p;
        p=(*start1);
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

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
}

void Traverse1(struct node** start1){
    struct node* p=(*start1);
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
}

int Concatanation(struct node** start,struct node** start1){
    if((*start)==NULL){
        printf("Can't concatanate\n");
        return 0;
    }
    else{
        struct node* p;
        p=(*start);
        while(p->next!=NULL){
           p=p->next;
        }
        p->next=(*start1);
        return 1;
    }
}

int main(){
    struct node* start,*start1;
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
    printf("Linked List: 1\n");
    Traverse(&start);

    printf("Linked List: 2\n");
    InsBeg1(&start1,10);
    InsBeg1(&start1,20);
    InsBeg1(&start1,30);
    InsBeg1(&start1,40);
    InsEnd1(&start1,50);
    InsAft1(&start1,30,60);
    InsBeg1(&start1,90);
    InsBeg1(&start1,75);
    Traverse1(&start1);
    int result=Concatanation(&start,&start1);
    printf("Result of Concatanation of Two Linked List %d\n",result);
    return 0;
}