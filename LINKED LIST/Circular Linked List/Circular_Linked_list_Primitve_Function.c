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

void InsBeg(struct node**cstart,int x){
    struct node* p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
    }
    else{
        (*cstart)=p;
        (*cstart)->next=(*cstart);
    }
}

void InsEnd(struct node**cstart,int x){
    struct node* p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        (*cstart)=p;
    }
    else{
        (*cstart)=p;
        (*cstart)->next=(*cstart);
    }
}

void InsAft(struct node**cstart,struct node**p,int x){
    if(p!=NULL){
        struct node* q=getnode();
        q->info=x;
        q->next=(*p)->next;
        (*p)->next=q;
    }
    else{
        printf("VOID INSERTION\n");
        exit(1);
    } 
}

int DelBeg(struct node**cstart){
    struct node* p;
    int x;
    if((*cstart)!=NULL){
        p=(*cstart)->next;
        x=p->info;
        (*cstart)->next=p->next;
        if((*cstart)=(*cstart)->next){
            (*cstart)=NULL;
        }
    }
    else{
        printf("VOID DELETION\n");
        exit(1);
    }
    free(p);
    return x;
}

int DelEnd(struct node**cstart){
    struct node* p;
    int x;
    if((*cstart)!=NULL){
        x=(*cstart)->info;
        p=*cstart;
        while(p->next!=(*cstart)){
            p=p->next;
        }
        p->next=(*cstart)->next;
        if((*cstart)==(*cstart)->next){
            (*cstart)=NULL;
        }
    }
    else{
        printf("VOID DELETION\n");
        exit(1);  
    }
    free(*cstart);
    (*cstart)=p;
    return x;
}

int DelAft(struct node**cstart,struct node**p){
    struct node* q;
    int x;
    if(p!=NULL){
        q=(*p)->next;
        (*p)->next=q->next;
        x=q->info;
    }
    else{
        printf("VOID DELETION\n");
        exit(1);  
    }
    free(q);
    return x;
}

void Traverse(struct node**cstart){
    struct node* p;
    p=(*cstart);
    while(p->next!=(*cstart)){
        printf("%d  \n",p->info);
        p=p->next;
    }
    printf("%d\n",p->info);
    printf("\n");
}

int main(){
    struct node* cstart;
    cstart=NULL;
    InsBeg(&cstart,100);
    InsBeg(&cstart,50);
    InsEnd(&cstart,200);
    InsEnd(&cstart,300);
    InsEnd(&cstart,400);
    InsEnd(&cstart,500);
    int c=0; scanf("%d",&c);
    struct node* p;
    p=cstart;
    while(c>0){
       p=p->next;
       c--;
    }
    InsAft(&cstart,&p,250);
    Traverse(&cstart);
    int y;
    y=DelBeg(&cstart);
    
    int z=DelEnd(&cstart);
    printf("%d %d\n",y,z);
    Traverse(&cstart);
    return 0;
}