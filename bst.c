 BST Menu Driven (Insert Search Traversals)

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node* r,int x)
{
    if(r==NULL)
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=x;
        r->left=r->right=NULL;
        return r;
    }

    if(x<r->data)
        r->left=insert(r->left,x);
    else
        r->right=insert(r->right,x);

    return r;
}

void inorder(struct node* r)
{
    if(r)
    {
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}

void preorder(struct node* r)
{
    if(r)
    {
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node* r)
{
    if(r)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->data);
    }
}

void search(struct node* r,int x)
{
    while(r)
    {
        if(x==r->data)
        {
            printf("Found");
            return;
        }
        if(x<r->data)
            r=r->left;
        else
            r=r->right;
    }
    printf("Not Found");
}

int main()
{
    struct node *root=NULL;
    int ch,x;

    do
    {
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                scanf("%d",&x);
                root=insert(root,x);
                break;
            case 2:
scanf("%d",&x);
                search(root,x);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
        }
    }
    while(ch!=6);

    return 0;
}