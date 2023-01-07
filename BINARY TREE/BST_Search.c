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


void BST_Insert(struct node** t,int x){
    struct node* p=(*t);
    struct node* q=NULL;
    if((*t)==NULL){
        (*t)=Makenode(x);
    }
    else{
        while(p!=NULL){
            q=p;
            if(x<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(x<q->data){
            q->left=Makenode(x);
        }
        else{
            q->right=Makenode(x);
        }

    }
}

struct node* BST_Search(struct node* t,int key){
    struct node* p;
    if(t->data==key){
        return t;
    }
    else{
        if(key<t->data){
            t=BST_Search(t->left,key);
        }
        else{
            t=BST_Search(t->right,key);
        }
    }
    return NULL;
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
    struct node *y=BST_Search(root,70);
    printf("\n%u",y);
    return 0;
}