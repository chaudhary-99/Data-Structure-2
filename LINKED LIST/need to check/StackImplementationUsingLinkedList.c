#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
struct node{
    int info;
    struct node* next;
};
struct node* getnode(){
   struct node* p;
   p=(struct node*)malloc(sizeof(struct node));
   return p;
}

void initialize(struct node** TOP){
	(*TOP)=NULL;
}

int Isempty(struct node** TOP){
	if((*TOP)==NULL){
		return true;
	}
	else{
		return false;
	}
}

void InsBeg(struct node** TOP,int x){
   struct node* p=getnode();
   p->info=x;
   p->next=(*TOP);
   (*TOP)=p;
}

int DelBeg(struct node** TOP){
    if((*TOP)==NULL){
        printf("Linked List is empty\n");
    }
    else{
        struct node* p;
        p=(*TOP);
        (*TOP)=(*TOP)->next;   
        int x= p->info;
        return x;
    }  
}

void push(struct node** TOP,int x){
        InsBeg(&(*TOP),x);
}

int pop(struct node** TOP){
		int x=DelBeg(&(*TOP));
		return x;
}

int stack_top(struct node** TOP){
	int x=(*TOP)->info;
    return x;
}

void Traverse(struct node** TOP){
    struct node* p=(*TOP);
    while(p!=NULL){
        printf("%d\n",p->info);
        p=p->next;
    }
}
int main(){
    struct node* TOP;
    initialize(&TOP);
    InsBeg(&TOP,100);
    InsBeg(&TOP,200);
    InsBeg(&TOP,300);
    InsBeg(&TOP,400);;
    InsBeg(&TOP,900);
    InsBeg(&TOP,750);
    printf("Deleted Value %d\n",pop(&TOP));
    printf("StackTopValue %d\n",stack_top(&TOP));
    Traverse(&TOP);
    return 0;
}