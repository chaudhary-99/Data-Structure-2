#include"LinLinkLst.h"

void InsBeg(struct node** start,int x){
   struct node* p=getnode();
   p->info=x;
   p->next=(*start);
   (*start)=p;
}

void PQInsertion(struct node** start,int y,int x){
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

int PQDeletion(struct node** start){
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

    PQInsBeg(&start,200,200);
    PQInsertion(&start,400,500);
    PQInsertion(&start,500,600);
    PQInsertion(&start,300,300);
    Traverse(&start);
    printf("\n");

    del=PQDeletion(&start);
    printf("Deleted_Element from Starting %d\n",del);
    Traverse(&start);
    printf("\n");
    
    return 0;
}