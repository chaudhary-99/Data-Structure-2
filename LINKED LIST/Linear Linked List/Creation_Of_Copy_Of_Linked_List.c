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
    if(*(p)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        struct node* q;
        q=getnode();
        q->info=x;
        q->next=(*p)->next;
        (*p)->next=q;
    }
}
void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
    printf("\n");
}

void Copying_Linked_List(struct node** start,struct node** start1){
    struct node* p,*q;
    p=*(start);
    q=*(start1);
    while((p)!=NULL){
        int x=p->info;
        if((*start1)!=NULL){
            InsEnd(&(*start1),x);
            p=p->next;
            
        }
        else{
            InsBeg(&(*start1),x);
            p=p->next;
        }
    }
    Traverse(&(*start1));
}

int main(){
    struct node* start=NULL;
    struct node* start1=NULL;
    InsBeg(&start,100);
    InsBeg(&start,200);
    InsBeg(&start,300);
    InsBeg(&start,400);
    InsEnd(&start,500);
    InsBeg(&start,900);
    InsBeg(&start,750);
    
    Traverse(&start);

    Copying_Linked_List(&start,&start1);
    return 0;
}