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
    p->father = NULL;
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


int IsLeft(struct node *t)
{
    if (t->father->left == t)
    {
        return 1;
    }
    else
        return 0;
}

int IsRight(struct node *t)
{
    if (t->father->right == t)
    {
        return 1;
    }
    else
        return 0;
}

struct node*  BSTMinimum(struct node* t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

struct node* BST_Successor(struct node *t){
    struct node*q;
    if(t->right!=NULL){
        q=BSTMinimum(t->right);
    }
    else{
        q=t->father;
        while(q!=NULL&&t==q->right){
            t=q;
            q=q->father;
        }
    }
    return q;

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

int  BST_Deletion(struct node **p)
{
    struct node *c;
    struct node *q;
    struct node *l;
    struct node *r;
    int x, y;
    if ((*p)->left == NULL && (*p)->right == NULL)
    {
        q = (*p)->father;
        if (IsLeft(*p))
        {
            (*p)->father->left = NULL;
        }
        else
        {
            (*p)->father->right = NULL;
        }
        x = (*p)->data;
        free(&(*p));
        
    }
    else
    {
        if ((*p)->left == NULL || (*p)->right == NULL)
        {
            q = (*p)->father;
            l = (*p)->left;
            r = (*p)->right;
            if (l == NULL)
            {
                q->right = r;
                r->father = q;
            }
            else
            {
                q->left = l;
                l->father = q;
            }
            x = (*p)->data;
            free(&(*p));
            
        }
        else{
            q=BST_Successor((*p));
            y=q->data;
            x=(*p)->data;
            (*p)->data=y;
            free(q);
            
        }
    }
    return x;
}

int main()
{
    struct node *root = NULL;
    BST_Insertion(&root, 100);
    BST_Insertion(&root, 50);
    BST_Insertion(&root, 200);
    BST_Insertion(&root, 20);
    BST_Insertion(&root, 60);
    BST_Insertion(&root, 150);
    BST_Insertion(&root, 300);
    PreOrderTraversal(root);
    printf("\n");
    struct node* y=BST_Search(root,200);
    int x=BST_Deletion(&y);
    printf("Deleted Value in BST %d",x);
    return 0;
}