#include <iostream>
#include<queue>
#include <stdlib.h>
using namespace std;
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

struct node* BST_Insertion(struct node** t,int x){
    if((*t)==NULL){
        (*t)=Makenode(x);
        return (*t);
    }
    else{
        if(x<(*t)->data){
            (*t)->left=BST_Insertion(&(*t)->left,x);
        }
        else{
            (*t)->right=BST_Insertion(&(*t)->right,x);
        }
    }
    return (*t);
}
int CheckBST(struct node* t){
    queue<struct node*> q;
    q.push(t);
    while(!q.empty()){
        struct node* x=q.front();
        q.pop();
        if((x->left->data)<(x->data)){
            q.push(x->left);
        }
        else{
            return 0;
        }
        if(x->right->data>x->data){
            q.push(x->right);
        }
        else{
            return 0;
        }
    }
    return 1;

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
    int result=CheckBST(root);
    if(result==0)  printf("THIS IS NOT A BST\n");
    else printf("THIS IS AN BST\n");
    return 0;
}