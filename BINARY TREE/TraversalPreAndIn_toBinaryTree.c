#include<stdio.h>
#include<stdlib.h>
struct denode{
    int info;
    struct denode* next;
    struct denode* prev;
};

struct denode* getnode(){
    struct denode *p;
    p=(struct denode*)malloc(sizeof(struct denode));
    return p;
}

void InsBeg(struct denode** dstart,int x){
    struct denode*p=getnode();
    p->next=(*dstart);
    p->info=x;
    p->prev=NULL;
    if((*dstart)!=NULL){
        (*dstart)->prev=p;
    }
    (*dstart)=p;
}

void InsEnd(struct denode** dstart,int x){
    struct denode* p=(*dstart);
    struct denode* q=getnode();
    q->info=x;
    q->next=NULL;
    if((*dstart)!=NULL){
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=q;
        q->prev=p;
    }
    else{
        q->prev=NULL;
        (*dstart)=q;
    }
}

void InsAft(struct denode**q,int x){
    if(q!=NULL){
       struct denode* p=getnode();
       struct denode* r;
       p->info=x;
       r=(*q)->next;
       r->prev=p;
       p->next=(*q)->next;
       (*q)->next=p;
       p->prev=(*q);
    }
    else{
        printf("VOID INSERTION\n");
    }
    
}

int DelBeg(struct denode**dstart){
    int x;
    return x;
}

void Traverse(struct denode**dstart){
    struct denode *p;
    p=(*dstart);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Makenode(int a)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}

void InOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        InOrderTraversal(t->left);
        printf("%d ", t->data);
        InOrderTraversal(t->right);
    }
}

void PostOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        printf("%d ", t->data);
    }
}

void CreateNode(struct node** p,int y){
    struct node* t;
    printf("whether left of %d exit?(0/1)\n",(*p)->data);
    scanf("%d",&choice);
    if(choice==1){ 
        printf("left Node  data \n"); 
        scanf("%d",&x);
        t= Makenode(x);
        (*p)->left=t;
        CreateNode(&t);
    }

    printf("whether right of %d exit?(0/1)\n",(*p)->data);
    scanf("%d",&choice);
    if(choice==1){  
        printf("Right Node  data");
        scanf("%d",&x);
        t= Makenode(x);
        (*p)->right=t;
        CreateNode(&t);

    }
    
}

void Binary_Tree(struct node** dstart1,struct node** dstart){
    struct denode* p=(*dstart);
    int x=(*dstart1)->info;
    while(){
        if(p->info==x){

        }
    }
}

int main(){
    struct denode* dstart1;
    struct denode* dstart;
    dstart1=NULL;
    dstart=NULL;
    InsBeg(&dstart,3);
    InsEnd(&dstart,12);
    InsEnd(&dstart,6);
    InsEnd(&dstart,4);
    InsEnd(&dstart,7);
    InsEnd(&dstart,10);
    InsEnd(&dstart,11);
    InsEnd(&dstart,5);
    InsEnd(&dstart,2);
    InsEnd(&dstart,8);
    Traverse(&dstart);

    InsBeg(&dstart1,10);
    InsEnd(&dstart1,12);
    InsEnd(&dstart,3);
    InsEnd(&dstart1,4);
    InsEnd(&dstart1,6);
    InsEnd(&dstart1,7);
    InsEnd(&dstart1,5);
    InsEnd(&dstart1,11);
    InsEnd(&dstart1,2);
    InsEnd(&dstart1,8);
    Traverse(&dstart1);
    Binary_Tree()

    43
    return 0;
}