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

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n \n");
}

struct node* MiddleElement(struct node** start){
    struct node* t,*r;
    t=(*start);
    r=(*start);
    while (r!=NULL&&r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t;

}

struct node* Binary_Search(struct node** start,int x){
    struct node* p=MiddleElement(&(*start));
    struct node* q=(*start);
    while((*start)->next!=NULL){
        if(p->info==x) return p;
        else{
            if(x>p->info){
                (*start)=p->next;
                return Binary_Search(&(*start),x);
            }
            else{
                p->next=NULL;
                return Binary_Search(&(*start),x);
            }
        }
    }
    if((*start)->info==x){
        return *start;
    }
    else{
        return NULL;
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
    InsEnd(&start,1000);
    Traverse(&start);
    int x;
    scanf("%d",&x);
    struct node* y=Binary_Search(&start,x);
    printf("%u %d",y,y->info);
    
    return 0;
}