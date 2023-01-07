#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
struct node* start;

struct node* getnode(){
   struct node* p;
   p=(struct node*)malloc(sizeof(struct node));
   return p;
}

void InsBeg(int x){
   struct node* p=getnode();
   p->info=x;
   p->next=start;
   start=p;
}


void InsEnd(int x){
    if(start==NULL){
        printf("LINKED LIST IS EMPTY\n");
    }
    else{
        struct node* p;
        p=start;
        while((p->next)!=NULL){
            p=p->next;
        }
        struct node* q=getnode();
        q->next=NULL;
        q->info=x;
        p->next=q;
    }
}

void InsAft(int y,int x){
    if(start==NULL){
        printf("INVALID NODE\n");
    }
    else{
        struct node* p;
        p=start;
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
void Traverse(){
    struct node* p=start;
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
}
int main(){
    start=NULL;
    struct node* p;
    InsBeg(100);
    InsBeg(200);
    InsBeg(300);
    InsBeg(400);
    Traverse();
    printf("\n");
    InsEnd(500);
    Traverse();
    printf("\n");
    InsAft(300,350);
    Traverse();
    return 0;
}