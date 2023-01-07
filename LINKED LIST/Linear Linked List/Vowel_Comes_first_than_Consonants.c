#include<stdio.h>
#include<stdlib.h>
struct node{
    char info;
    struct node* next;
};


struct node* getnode(){
   struct node* p;
   p=(struct node*)malloc(sizeof(struct node));
   return p;
}

void InsBeg(struct node** start,char x){
   struct node* p=getnode();
   p->info=x;
   p->next=(*start);
   (*start)=p;
}


void InsEnd(struct node** start,char x){
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

void InsAft(struct node** p,char x){
    struct node* q;
    q=getnode();
    q->info=x;
    q->next=(*p)->next;
    (*p)->next=q;
}

void OrderedIns(struct node**start,char x){
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
    else  InsAft(&q,x);
}

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%c ",p->info);
        p=p->next;
    }
}
int DelBeg(struct node** start){
    if((*start)==NULL){
        printf("Linked List is empty\n");
    }
    else{
        struct node* p;
        p=(*start);
        (*start)=(*start)->next;   
        char x= p->info;
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
        char x=p->info;
        q->next=NULL;
        free(p);
        return x;
    }
}
int DelAft(struct node** start,struct node** p){
    if((*p)==NULL){
        printf("INVALID NODE\n");
    }
    else{
        char x;
        struct node* q;
        q=(*p)->next;
        x=q->info;
        (*p)->next=q->next;
        return x;
    }
}

void Vowel_Come_First_Than_Consonants(struct node **start){
    struct node* p,*q,*r;
    p=NULL;
    r=NULL;
    q=(*start);
    char x;
    while(q!=NULL){
        if(q->info=='a'||q->info=='e'||q->info=='i'||q->info=='o'||q->info=='u'){
            q=q->next;
            if(p==NULL){
                if(r!=NULL){
                    x=DelAft(&(*start),&r);
                    InsBeg(&(*start),x);
                    p=*start;
                }
                else{
                    p=*(start);
                    r=p;
                }
            }
            else{
                if(r==p){
                    p=p->next;
                    r=r->next;
                }
                else{
                    x=DelAft(&(*start),&r);
                    InsAft(&p,x);
                    p=p->next;
                } 
            }
        }
        else{
            r=q;
            q=q->next;
        }
    }
    Traverse(&(*start));

}
int main(){
    struct node* start;
    start=NULL;
    InsBeg(&start,'a');
    InsBeg(&start,'i');
    InsBeg(&start,'t');
    InsBeg(&start,'e');
    InsBeg(&start,'u');
    Traverse(&start);
    printf("\n");
    Vowel_Come_First_Than_Consonants(&start);
    return 0;
}