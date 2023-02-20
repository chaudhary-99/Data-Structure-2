#include <iostream>
#include <stdlib.h>
#include<vector>
#include<queue>
using namespace std;
struct node
{
    int data;
    int hd;
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

int TopViewTraversal(struct node** t){
   queue<struct node*>q;

    int h=MaxHeight(*t);

    vector<int>Ht[(2*h)+1];
    q.push((*t));

    (*t)->hd=0;

    Ht[(*t)->hd+h].push_back((*t)->data);

    while(!q.empty()){

        struct node* x=q.front();
        q.pop();
        if(x->left!=NULL){
            
            q.push(x->left);
            x->left->hd=x->hd-1;
            Ht[x->left->hd+h].push_back(x->left->data);

        }
        if(x->right!=NULL){
            q.push(x->right);
            x->right->hd=x->hd+1;
            Ht[x->right->hd+h].push_back(x->right->data);
        }
    }

    printf("Bottom View Traversal : ");
    for(int i=0;i<(2*h)+1;i++){
        if(Ht[i].size()!=0)
           printf("%d ",Ht[i][Ht[i].size()-1]);
    }
}


 

int main()
{
    struct node *root = NULL;
    int x;
    scanf("%d",&x);
    root=Makenode(x);

    CreateNode(&root);
    /*root=Makenode(1);
    root->left = Makenode(2);
    root->right = Makenode(3);
    root->left->right = Makenode(5);
    root->left->left = Makenode(4);
    root->right->left = Makenode(6);
    root->right->right = Makenode(7);*/
    
    PreOrderTraversal(root);
    printf("\n");
    TopViewTraversal(&root);
    printf("\n");
    
    return 0;
}