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
int DelAft(struct node** start,int y){
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
        struct node* q;
        q=p->next;
        int x=q->info;
        p->next=q->next;
        return x;
    }
}

int count_node(struct node** start){
    int count=0;
    struct node* p=(*start);
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}

void Insert(int x,int y,struct node** start){
    int l=count_node(&(*start));
    if(y==1){
        InsBeg(&(*start),x);
    }
    else if(y==l+1){
        InsEnd(&(*start),x);
    }
    else if(y>1&&y<=l){
        struct node* p;
        p=(*start);
        for(int i=0;i<y;i++){
            p=p->next;
        }
        InsAft(&p,x);
    }
    else{
        printf("Void Insertion\n");
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
    struct node* p;
    InsBeg(&start,100);
    InsBeg(&start,200);
    InsBeg(&start,300);
    InsBeg(&start,400);
    InsEnd(&start,500);
    InsBeg(&start,900);
    InsBeg(&start,750);
    printf("Before Insertion\n");
    Traverse(&start);
    printf("After Insertion\n");
    int pos;
    scanf("%d",&pos);
    Insert(4000,pos,&start);
    Traverse(&start);
    
    return 0;
}