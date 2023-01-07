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

void Deleting_kth_Value_from_end(struct node**start ,int x){
    struct node* p=(*start);
    int i=1;
    while(i<x){
        if(p!=NULL){
             p=p->next;
        }
        else{
            printf("VOID PLACE\n");
            break;
        }
        i++;
    }
    struct node* t=NULL;
    struct node* q=(*start);
    if(p!=NULL){
        while(p->next!=NULL){
            t=q;
            q=q->next;
            p=p->next;
        }
        DelAft(&t);
    }
    else{
        DelBeg(&(*start));  
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}

int main(){
    struct node* start;
    start=NULL;
    InsBeg(&start,100);
    InsEnd(&start,200);
    InsEnd(&start,300);
    InsEnd(&start,400);
    InsEnd(&start,500);
    InsEnd(&start,900);
    InsEnd(&start,750);
    Traverse(&start);
    int del;
    struct node* p;
    p=start;
    while(p!=NULL){
        if(p->info==300){
            break;
        }
        else{
           p=p->next;
        }  
    }
    del=DelAft(&p);
    printf("%d\n",del);
    Traverse(&start);
    int k;
    scanf("%d",&k);
    Deleting_kth_Value_from_end(&start,k);
    Traverse(&start);
    return 0;
}