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
    r

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

void CreateNode(struct node** p){
    int choice,x;
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
void Split_LL(struct dnode**dstart1,struct dnode** m){
    struct node* p=(*m);
    struct node* q=*dstart1;
    struct node* start1;
    start1=p->next;
    p->next=NULL;

}

void Make_Binary_Tree(int pre_Order[],int in_Order[],int start,int end){
    int ind=0;
    int curr=

}

int main(){
    int pre_Order[10]={1,2,4,5,7,3,6,8};
    int in_Order[10]={4,2,7,5,1,8,6,3};
    Binary_Tree()
    return 0;
}