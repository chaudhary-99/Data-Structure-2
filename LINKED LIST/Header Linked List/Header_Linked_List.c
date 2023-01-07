#include<stdio.h>
#include<stdlib.h>
struct hnode{
    int info;
    struct hnode* next;
};
struct hnode* gethnode(){
   struct hnode* p;
   p=(struct hnode*)malloc(sizeof(struct hnode));
   return p;
}

void InsEnd(struct hnode** head,int x){
    if((*head)==NULL){
        printf("LINKED LIST IS EMPTY\n");
    }
    else{
        struct hnode* p;
        p=(*head);
        while((p->next)!=NULL){
            p=p->next;
        }
        struct hnode* q=gethnode();
        q->next=NULL;
        q->info=x;
        p->next=q;
        (*head)->info++;
    }
}
void InsAft(struct hnode** head,struct hnode** p,int x){
    struct hnode* q;
    q=gethnode();
    q->info=x;
    q->next=(*p)->next;
    (*p)->next=q;
    (*head)->info++;
}

void InsBeg(struct hnode** head,int x){
    InsAft(&(*head),&(*head),x);
}

void Traverse(struct hnode**head){
    struct hnode* p=(*head);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
}
int main(){
    struct hnode* head;
    head=gethnode();
    head->info=0;
    InsBeg(&head,10);
    InsEnd(&head,20);
    InsEnd(&head,30);
    printf("%d",head->info);
    Traverse(&head);
    return 0;
}

/*
int DelBeg(struct hnode**head){
    if(((*head)->next)==NULL){
        printf("Linked List is empty\n");
    }
    else{
        struct hnode* p;
        p=(head);
        (*head)=(*head)->next;   
        int x= p->info;
        free(p);
        return x;
    }  
}

int DelEnd(struct hnode**head){
    if((head)==NULL){
        printf("Linked List is Empty\n");
    }
    else{
        struct hnode* p,*q;
        q=NULL;
        p=(head);
        while((p->next)!=NULL){
            q=p;
            p=p->next;
        }
        char x=p->info;
        q->next=NULL;
        free(p);
        return x;
    }
}
int DelAft(struct hnode**head,struct hnode** p){
    if((*p)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        char x;
        struct hnode* q;
        q=(*p)->next;
        x=q->info;
        (*p)->next=q->next;
        return x;
    }
}
*/