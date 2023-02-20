#include <iostream>
#include <stdlib.h>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int data;
    int level;
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
int MaxHeight(struct node *t)
{
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        if (t->left == NULL && t->right == NULL)
            return 0;
        else
        {
            return max(MaxHeight(t->left),MaxHeight(t->right))+1;
        }
    }
}

int LeftViewTraversal(struct node** t){
   queue<struct node*>q;

    int h=MaxHeight(*t);

    vector<int>Ht[h+1];

    q.push((*t));

    (*t)->level=0;

    Ht[(*t)->level].push_back((*t)->data);

    while(!q.empty()){

        struct node* x=q.front();
        q.pop();
        if(x->left!=NULL){
            
            q.push(x->left);
            x->left->level=x->level+1;
            Ht[x->left->level].push_back(x->left->data);

        }
        if(x->right!=NULL){
            q.push(x->right);
            x->right->level=x->level+1;
            Ht[x->right->level].push_back(x->right->data);
        }
    }

    printf("Left View Traversal : ");
    for(int i=0;i<h+1;i++){
        printf("%d ",Ht[i][0]);
    }
}




int main()
{
    struct node *root = NULL;
    root=Makenode(1);
    root->left = Makenode(2);
    root->right = Makenode(3);
    root->left->right = Makenode(5);
    root->left->left = Makenode(4);
    root->right->left = Makenode(6);
    root->right->right = Makenode(7);
    
    PreOrderTraversal(root);
    printf("\n");
    LeftViewTraversal(&root);
    printf("\n");
    
    return 0;
}