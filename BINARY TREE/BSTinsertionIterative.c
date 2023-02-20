#include <stdio.h>
#include <stdlib.h>
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

void BST_Insertion(struct node** t,int x){
    if((*t)==NULL){
        (*t)=Makenode(x);
    }
    else{
     struct node * p=(*t);
   struct node* q=NULL;
   while(p!=NULL){
    if(x<p->data){
        q=p;
        p=p->left;
    }
    else{
        q=p;
        p=p->right;
    }
   }
   if(x<q->data)
        q->left=Makenode(x);
    else 
        q->right=Makenode(x);
    }
   
}





int main()
{
    struct node *root = NULL;
    BST_Insertion(&root,100);
    BST_Insertion(&root,50);
    BST_Insertion(&root,200);
    BST_Insertion(&root,20);
    BST_Insertion(&root,60);
    BST_Insertion(&root,150);
    BST_Insertion(&root,300);
    PreOrderTraversal(root);
    printf("\n");
    return 0;
}