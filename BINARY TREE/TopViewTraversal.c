#include<stdio.h>
#include<stdlib.h>
#define Queuesize 7
#define TRUE 1
#define FALSE 0
int HashTable[10][10]={0};
struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};

struct node* front;
struct node* rear;

struct node* Makenode(int x){
    struct node* p;
    p=(struct node*) malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}

void initialise(){
    (rear)=NULL;
    front=NULL;
}

int isempty(){
    if(front==NULL)
        return TRUE;
    else 
        return FALSE;
}

void enqueue(struct node**p){
    if((front)!=NULL){
        (rear)->next=(*p);
    }
    else{
        (front)=(*p);
    }
    (rear)=(*p);
}

struct node* dequeue(){
    struct node* p;
    p=front;
    (front)=(front)->next;
    if((front)==NULL){
        (rear)=NULL;
    }
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

void LevelOrderTraversal(struct node **t){
   initialise();
   enqueue(*(&t));
   struct node* x;
    while(!isempty()){
      x=dequeue();
      printf("%d",x->data)m;
      if(x->left!=NULL){
        enqueue(&(x->left));
      }
      if(x->right!=NULL){
        enqueue((&x->right));
      }   
   }
}

int main(){
    struct node *root = NULL;
    int x;
    scanf("%d",&x);
    root=Makenode(x);

    CreateNode(&root);
    printf("PreOrderTraversal\n");
    PreOrderTraversal(root);
    printf("\n");
    printf("InOrderTraversal\n");
    InOrderTraversal(root);
    printf("\n");
    printf("PostOrderTraversal\n");
    PostOrderTraversal(root);
    printf("\n");
    printf("LevelOrderTraversal\n");
    LevelOrderTraversal(&root);
    printf("\n");

    return 0;
}
