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

void BST_Insert(struct node **t, int x)
{
    struct node *q = NULL;
    struct node *p = (*t);
    if (p== NULL)
    {
        (*t)= Makenode(x);
    }
    else
    {
        while (p != NULL)
        {
            q = p;

            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }

        if (x < q->data)
        {
            q->left = Makenode(x);
        }
        else
        {
            q->right = Makenode(x);
        }
    }
    
}

struct node *BST_Search(struct node *t, int key)
{
    while (t != NULL)
    {
        if (t->data == key)
        {
            return t;
        }
        else
        {
            if (t->data < key)
            {
                BST_Search(t->right, key);
            }
            else
            {
                BST_Search(t->left, key);
            }
        }
    }
    return NULL;
}

int BST_Minimum(struct node *t)
{

    while (t->left!= NULL)
    {
        t = t->left;
    }
    return t->data;
}

int BST_Maximum(struct node *t)
{
    while (t->right != NULL)
    {
        t = t->right;
    }
    return t->data;
}
int BT_Successor(struct node* p){
    struct node*q;
    if(p->right!=NULL){
        BST_Minimum(p->right);
    }
    else{
        q=q->father;
    }
    while(q!=NULL&&q->right==p){
        p=q;
        q=q->father;
    }
    return q->data;
}
int main()
{
    struct node *root = NULL;
    BST_Insert(&root, 100);
    BST_Insert(&root, 50);
    BST_Insert(&root, 70);
    BST_Insert(&root, 130);
    BST_Insert(&root, 150);
    BST_Insert(&root, 20);
    BST_Insert(&root, 40);
    BST_Insert(&root, 30);
    InOrderTraversal(root);
    printf("\nsuccessor\n");
    struct node* p;
    p=BST_Search(root,70);
    printf("%d\n", BT_Successor(p));


    return 0;
}