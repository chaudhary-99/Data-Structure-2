
#include<stdio.h>
#include<stdlib.h>
#define stacksize 20
#define true 1
#define false 0
struct stack{
	int item[stacksize];
	int TOP;
};
struct stack s;

void initialize(){
	s.TOP=-1;
}

int Isempty(){
	if(s.TOP==-1){
		return true;
	}
	else{
		return false;
	}
}

void push(int x){
	if(s.TOP==stacksize-1){
		printf("STACK OVERFLOW");
		exit(1);
	}
	else{
		s.TOP=s.TOP+1;
		s.item[s.TOP]=x;
	}
}

int pop(){
	if(Isempty ()){
		printf("STACK UNDERFLOW");
		exit(1);
	}
	else{
		int x=s.item[s.TOP];
		s.TOP=s.TOP-1;
		return x;
	}
}

int stack_top(){
	int x=s.item[s.TOP];
	return x;
}
/********************************/
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
    else  InsAft(&q,x);
}

void Traverse(struct node** start){
    struct node* p=(*start);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}
void ReversingLL(struct node **start){
    struct node* p;
    p=*start;
    initialize();
    while(p!=NULL){
        int x=p->info;
        push(x);
        p=p->next;
    }
    p=(*start);
    while(!Isempty()){
        int x=pop();
        p->info=x;
        p=p->next;
    }
}
int main(){
    struct node* start=NULL;
    InsBeg(&start,10);
    InsEnd(&start,30);
    InsEnd(&start,33);
    InsEnd(&start,22);
    Traverse(&start);
    ReversingLL(&start);
    Traverse(&start);
     return 0;
}