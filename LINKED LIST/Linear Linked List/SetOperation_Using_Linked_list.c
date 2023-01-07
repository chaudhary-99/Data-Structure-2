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

void OrderedIns(struct node**start,int x){
    struct node* p,*q;
    p=(*start);
    q=NULL;
    while(p!=NULL&&x>=p->info){
        q=p;
        p=p->next;
    }
    if(q==NULL){
        InsBeg(&(*start),x);
    }
    else{
        InsAft(&q,x);
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

void Union(struct  node* start1,struct node*start2){
    struct node* p,*q,*start3;

    p=start1; q=start2; start3=NULL;

    while(p!=NULL&&q!=NULL){
        if((p->info)<(q->info)){
            OrderedIns(&start3,p->info);
            p=p->next;
        }
        else if((p->info)>(q->info)){
            OrderedIns(&start3,q->info);
            q=q->next;
        }
        else{
            OrderedIns(&start3,q->info);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        OrderedIns(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        OrderedIns(&start3,q->info);
        q=q->next;
    }
    Traverse(&start3);
}

void Intersection(struct  node* start1,struct node*start2){
    struct node* p,*q,*start3;

    p=start1; q=start2; start3=NULL;

    while(p!=NULL&&q!=NULL){
        if((p->info)<(q->info)){
            p=p->next;
        }
        else if((p->info)>(q->info)){
            q=q->next;
        }
        else{
            OrderedIns(&start3,q->info);
            p=p->next;
            q=q->next;
        }
    }
    Traverse(&start3);
}

void Merge(struct  node* start1,struct node*start2){
    struct node* p,*q,*start3;

    p=start1; q=start2; start3=NULL;

    while(p!=NULL&&q!=NULL){
        if((p->info)<(q->info)){
            OrderedIns(&start3,p->info);
            p=p->next;
        }
        else if((p->info)>(q->info)){
            OrderedIns(&start3,q->info);
            q=q->next;
        }
        else{
            OrderedIns(&start3,q->info);
            OrderedIns(&start3,q->info);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        OrderedIns(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        OrderedIns(&start3,q->info);
        q=q->next;
    }
    Traverse(&start3);
}

void Differnce(struct  node* start1,struct node*start2){
    struct node* p,*q,*start3;

    p=start1; q=start2; start3=NULL;

    while(p!=NULL&&q!=NULL){
        if((p->info)<(q->info)){
            OrderedIns(&start3,p->info);
            p=p->next;
        }
        else if((p->info)>(q->info)){
            
            q=q->next;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        OrderedIns(&start3,p->info);
        p=p->next;
    }
    Traverse(&start3);
}

void Symmetric_differnece(struct  node* start1,struct node*start2){
    struct node* p,*q,*start3;

    p=start1; q=start2; start3=NULL;

    while(p!=NULL&&q!=NULL){
        if((p->info)<(q->info)){
            OrderedIns(&start3,p->info);
            p=p->next;
        }
        else if((p->info)>(q->info)){
            OrderedIns(&start3,q->info);
            q=q->next;
        }
        else{
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        OrderedIns(&start3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        OrderedIns(&start3,q->info);
        q=q->next;
    }
    Traverse(&start3);
}

int main(){
    struct node* start1,*start2;
    start1=NULL;
    start2=NULL;
    OrderedIns(&start1,100);
    OrderedIns(&start1,200);
    OrderedIns(&start1,300);
    OrderedIns(&start1,400);
    OrderedIns(&start1,350);
    OrderedIns(&start1,900);
    OrderedIns(&start1,750);
    Traverse(&start1);
    printf("\n");
    OrderedIns(&start2,100);
    OrderedIns(&start2,250);
    OrderedIns(&start2,300);
    OrderedIns(&start2,400);
    OrderedIns(&start2,370);
    OrderedIns(&start2,950);
    OrderedIns(&start2,750);
    Traverse(&start2);
    printf("\n");
    Union(start1,start2);
    Intersection(start1,start2);
    Differnce(start1,start2);
    Symmetric_differnece(start1,start2);
    Merge(start1,start2);
    return 0;
}