#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
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

void Making_Circular_linked_list(struct node** start){
    struct node* p=(*start);
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=(*start);
    (*start)=p;
}

int CycleDetection(struct node**start){
    struct node* t,*r;
    t=(*start);
    r=(*start);
    while (r!=NULL&&r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            return true;
        }
    }
    return false;

}

int CycleLength(struct node** start){
    struct node* t,*r;
    t=(*start);
    r=(*start);
    while (r!=NULL&&r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            break;
        }
    }
    int length=0;

    do{
        length++;
        t=t->next;
    }while(t!=r);
    return length;
}

int CycleStartingPoint(struct node** start){
    struct node* t,*r;
    t=(*start);
    r=(*start);
    while (r!=NULL&&r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            break;
        }
    }
    t=(*start);
    while(t!=r){
        t=t->next;
        r=r->next;
    }
    return t->info;
}

int DelBeg(struct node** start){
    if((*start)!=NULL){
        struct node* p;
        int x;
        p=(*start)->next;
        x=p->info;
        (*start)->next=p->next;
    
        if((*start)->next=(*start)){
            (*start)=NULL;
        }
        free(p);
        return x;
    }
    else{
        printf("VOID DELETION\n");
    }
   
}

int DelEnd(struct node** start){
   if((*start)!=NULL){
        int x;
        struct node* p;
        while (p->next!=*start)
        {
            p=p->next;
        }
        x=(*start)->info;
        p->next=(*start)->next;
        if((*start)==(*start)->next){
            (*start)=NULL;
        }
        free(*start);
        (*start)=p;
        return x;
    
    }
    else{
       printf("VOID DELETION\n");
    }

}

int DelAft(struct node** start,struct node** q){
    if(*q=NULL){
        printf("VOID DELETION\n");
    }
    else{
        struct node* p;
        p=(*q)->next;
        int x=p->info;
        (*q)->next=p->next;
        if((*start)==(*start)->next){
            (*start)=NULL;
        }
        free(p);
        return x;
    }
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

    InsBeg(&start,100);
    InsBeg(&start,200);
    InsBeg(&start,300);
    InsBeg(&start,400);
    InsEnd(&start,500);
    InsAft(&start,300,350);
    InsAft(&start,100,150);
    InsBeg(&start,800);
    InsBeg(&start,750);
    Traverse(&start);

    Making_Circular_linked_list(&start);
    
    int ans=CycleDetection(&start);
    printf("Cycle Detection %d\n",ans);

    int length=CycleLength(&start);
    printf("Cycle Length %d\n",length);
    
    int value=CycleStartingPoint(&start);
    printf("Starting Point of Cycle %d\n",value);
    
    int y;
    y=DelBeg(&start);
    printf("Deleted Element %d\n",y);
    Traverse(&start);
    printf("\n \n");

    return 0;
}