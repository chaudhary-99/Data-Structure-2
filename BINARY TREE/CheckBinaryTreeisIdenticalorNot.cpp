#include<iostream>
#include <stdlib.h>
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
int Check_Binary_Tree(struct node* root1,struct node* root2){
    queue<struct node*>q1;
    queue<struct node*>q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty()||!q2.empty()){
        struct node* x=q1.front();
        q1.pop();
        struct node* y=q2.front();
        q2.pop();
        if(x->data==y->data){
            if(x->left!=NULL&&y->left!=NULL){
                q1.push(x->left);
                q2.push(y->left);
            }
            if(x->right!=NULL&&y->right!=NULL){
                q1.push(x->right);
                q2.push(y->right);
            }
        }
        else{
            return 0 ;
        }
    }
    return 1;

}
int main()
{
    struct node *root1 = NULL;
    struct node* root2=NULL; 
    root1=Makenode(1);
    root2=Makenode(1);
    root1->left = Makenode(2);
    root1->right = Makenode(3);
    root1->left->right = Makenode(5);
    root1->left->left = Makenode(4);
    root1->right->left = Makenode(6);
    root1->right->right = Makenode(7);

    root2->left = Makenode(2);
    root2->right = Makenode(3);
    root2->left->right = Makenode(5);
    root2->left->left = Makenode(8);
    root2->right->left = Makenode(6);
    root2->right->right = Makenode(7);

    PreOrderTraversal(root1);
    printf("\n");
    PreOrderTraversal(root2);
    printf("\n");
   
    int result =Check_Binary_Tree(root1,root2);
    if(result==1) printf("Identical BST\n");
    else printf("Not Identical\n");
    return 0;
}