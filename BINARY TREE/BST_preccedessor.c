#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

struct node *Makenode(int a)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = a;
    p->left = NULL;
    p->right = NULL;
    p->father=NULL;
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
struct node*  BSTMaximum(struct node* t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t;
}

struct node *BST_Search(struct node *t, int key)
{
    while (t != NULL)
    {
        if (t->data == key)
            return t;
        else
        {
            if (key < t->data)
                t = t->left;
            else
                t = t->right;
        }
    }
}

   struct node* BST_Insertion(struct node** t,int x){
    struct node* q;
    if((*t)==NULL){
        (*t)=Makenode(x);
        return (*t);
    }
    else{
        if(x<(*t)->data){
            q=BST_Insertion(&(*t)->left,x);
            q->father=(*t);
            (*t)->left=q;
        }
        else{
            q=BST_Insertion(&(*t)->right,x);
            q->father=(*t);
            (*t)->right=q;
        }
    }
    return (*t);
}
struct node* BST_Preccedessor(struct node *t){
    struct node*q;
    if(t->right!=NULL){
        q=BSTMaximum(t->left);
    }
    else{
        q=t->father;
        while(q!=NULL&&t==q->left){
            t=q;
            q=q->father;
        }
    }
    return q;

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
    struct node* x=BST_Search(root,200);
    struct node* y=BST_Preccedessor(x);
    if(y!=NULL) printf("Preccedessor is : %u",y->data);
    else printf("Preccedessor donot exist\n");
    return 0;
}