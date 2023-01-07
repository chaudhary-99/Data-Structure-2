#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *Makenode(char a)
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
        printf("%c ", t->data);
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}

void InOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        InOrderTraversal(t->left);
        printf("%c ", t->data);
        InOrderTraversal(t->right);
    }
}

void PostOrderTraversal(struct node *t)
{
    if (t != NULL)
    {
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        printf("%c ", t->data);
    }
}

int main()
{
    struct node *root = NULL;

    root = Makenode('A');

    root->left = Makenode('B');
    root->right = Makenode('C');
    root->left->right = Makenode('D');
    root->left->left = Makenode('E');
    root->right->left = Makenode('F');
    root->right->right = Makenode('G');

    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    printf("\n");
    PostOrderTraversal(root);

    return 0;
}