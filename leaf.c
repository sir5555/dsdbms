#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node* root,int x)
{
    if(root==NULL)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=x;
        root->left=root->right=NULL;
        return root;
    }

    if(x<root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);

    return root;
}

int totalNodes(struct node* root)
{
    if(root==NULL)
        return 0;
    return 1+totalNodes(root->left)+totalNodes(root->right);
}

int leafNodes(struct node* root)
{
    if(root==NULL)
        return 0;

    if(root->left==NULL && root->right==NULL)
        return 1;

    return leafNodes(root->left)+leafNodes(root->right);
}

int main()
{
    struct node *root=NULL;
    int n,x,i;

    printf("Enter no of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        root=insert(root,x);
    }

    printf("Total Nodes=%d",totalNodes(root));
    printf("\nLeaf Nodes=%d",leafNodes(root));

    return 0;
}