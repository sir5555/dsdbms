Height of Tree and Balanced Check

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

int height(struct node* r)
{
    if(r==NULL)
        return 0;

    int l=height(r->left);
    int h=height(r->right);

    if(l>h)
        return l+1;
    else
        return h+1;
}

int balanced(struct node* r)
{
    int l=height(r->left);
    int h=height(r->right);

    if(l-h<=1 && h-l<=1)
        return 1;
    else
        return 0;
}

int main()
{
    struct node* root=newnode(10);
    root->left=newnode(20);
    root->right=newnode(30);
    root->left->left=newnode(40);

    printf("Height=%d\n",height(root));

    if(balanced(root))
        printf("Balanced Tree");
    else
        printf("Not Balanced");

    return 0;
}

