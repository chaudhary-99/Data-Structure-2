#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int exp;
    struct node* next;
};
struct node* getnode(){
    struct node* p;
    p=(struct node*) malloc(sizeof(struct node));
    return p;
}

void InsBeg(struct node** poly,int c,int e){
   struct node* p=getnode();
   p->coef=c;
   p->exp=e;
   p->next=(*poly);
   (*poly)=p;
}


void InsEnd(struct node** poly,int c,int e){
    if((*poly)==NULL){
        printf("LINKED LIST IS EMPTY\n");
    }
    else{
        struct node* p;
        p=(*poly);
        while((p->next)!=NULL){
            p=p->next;
        }
        struct node* q=getnode();
        q->next=NULL;
        q->coef=c;
        q->exp=e;
        p->next=q;
    }
}

void InsAft(struct node** p,int c,int e){
    struct node* q;
    q=getnode();
    q->coef=c;
    q->exp=e;
    q->next=(*p)->next;
    (*p)->next=q;
}

void Traverse(struct node** poly){
    struct node* p=(*poly);
    while(p!=NULL){
        printf("%dx^%d ",p->coef,p->exp);
        p=p->next;
    }
    printf("\n \n");
}

void Adding_Polynomial(struct node**poly1,struct node**poly2){
    struct node* poly3;
    poly3=NULL;
    struct node*p=(*poly1);
    struct node*q=(*poly2);
    while(p!=NULL&&q!=NULL){
        if(p->exp==q->exp){
            if(poly3!=NULL){
                InsEnd(&poly3,p->coef-q->coef,p->exp);
                p=p->next;
                q=q->next;
            }
            else{
                InsBeg(&poly3,p->coef-q->coef,p->exp);
                p=p->next;
                q=q->next;
            }
        }
        else{
            if(p->exp>q->exp){
                if(poly3!=NULL){
                    InsEnd(&poly3,p->coef,p->exp);
                    p=p->next;
                }
                else{
                    InsBeg(&poly3,p->coef,p->exp);
                    p=p->next;
                }
              
            }
            else{
                if(poly3!=NULL){
                    InsEnd(&poly3,q->coef,q->exp);
                    q=q->next;
                }
                else{
                    InsBeg(&poly3,q->coef,q->exp);
                    q=q->next;
                }
            }
        }
    }
    while(p!=NULL){
        InsEnd(&poly3,p->coef,p->exp);
        p=p->next;
    }
    while(q!=NULL){
        InsEnd(&poly3,p->coef,p->exp);
        p=p->next;
    }
    Traverse(&poly3);
}
int main(){
    struct node* poly1;
    struct node* poly2;
    poly1=NULL;
    poly2=NULL;
    InsBeg(&poly1,4,7);
    InsEnd(&poly1,-2,5);
    InsEnd(&poly1,1,4);
    InsEnd(&poly1,5,2);
    InsEnd(&poly1,2,0);
    Traverse(&poly1);

    InsBeg(&poly2,8,6);
    InsEnd(&poly2,4,5);
    InsEnd(&poly2,-3,3);
    InsEnd(&poly2,2,2);
    InsEnd(&poly2,7,1);
    InsEnd(&poly2,-7,0);
    Traverse(&poly2);

    Adding_Polynomial(&poly1,&poly2);
    return 0;
}