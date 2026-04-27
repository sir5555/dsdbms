 BST Min and Max

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* newnode(int x)
{
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

int min(struct node* r)
{
    while(r->left!=NULL)
        r=r->left;
    return r->data;
}

int max(struct node* r)
{
    while(r->right!=NULL)
        r=r->right;
    return r->data;
}

int main()
{
    struct node* root=newnode(50);
    root->left=newnode(30);
    root->right=newnode(70);
    root->left->left=newnode(20);
    root->right->right=newnode(80);

    printf("Minimum=%d\n",min(root));
    printf("Maximum=%d",max(root));
    return 0;
}

