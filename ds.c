1) Prim’s Minimum Spanning Tree

#include<stdio.h>

int main()
{
    int c[5][5]={
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    int s[5]={1,0,0,0,0};
    int e=0,min,x,y,i,j,cost=0;

    while(e<4)
    {
        min=999;
        for(i=0;i<5;i++)
        {
            if(s[i])
            {
                for(j=0;j<5;j++)
                {
                    if(!s[j] && c[i][j] && c[i][j]<min)
                    {
                        min=c[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }

        printf("%d-%d=%d\n",x,y,min);
        cost=cost+min;
        s[y]=1;
        e++;
    }

    printf("Minimum Cost=%d",cost);
    return 0;
}

2) Heap Sort (Print Heap + Sorted)

#include<stdio.h>

void heapify(int a[],int n,int i)
{
    int largest=i,l=2*i+1,r=2*i+2,temp;

    if(l<n && a[l]>a[largest])
        largest=l;

    if(r<n && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

void heapsort(int a[],int n)
{
    int i,temp;

    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);

    printf("Heap:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}

int main()
{
    int a[]={12,11,13,5,6,7};
    int n=6,i;

    heapsort(a,n);

    printf("\nSorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

3) BST Min and Max

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

4) Height of Tree and Balanced Check

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

5) Adjacency List + BFS + DFS

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int v;
    struct node *next;
};

struct node *a[10];
int visit[10], q[10], f=0, r=-1, n;

void add(int u,int v)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->v=v;
    t->next=a[u];
    a[u]=t;
}

void bfs(int s)
{
    struct node *p;
    visit[s]=1;
    q[++r]=s;

    while(f<=r)
    {
        s=q[f++];
        printf("%d ",s);

        p=a[s];
        while(p)
        {
            if(!visit[p->v])
            {
                visit[p->v]=1;
                q[++r]=p->v;
            }
            p=p->next;
        }
    }
}

void dfs(int s)
{
    struct node *p;
    visit[s]=1;
    printf("%d ",s);
p=a[s];
    while(p)
    {
        if(!visit[p->v])
            dfs(p->v);
        p=p->next;
    }
}

int main()
{
    int i,e,u,v;
    scanf("%d%d",&n,&e);

    for(i=0;i<n;i++)
        a[i]=NULL;

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }

    for(i=0;i<n;i++)
    {
        struct node *p=a[i];
        printf("%d->",i);
        while(p)
        {
            printf("%d->",p->v);
            p=p->next;
        }
        printf("NULL\n");
    }

    printf("BFS: ");
    bfs(0);

    for(i=0;i<n;i++)
        visit[i]=0;

    printf("\nDFS: ");
    dfs(0);

    return 0;
}

6) Adjacency List + Indegree Outdegree

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int v;
    struct node *next;
};

struct node *a[10];
int in[10],out[10],n;

void add(int u,int v)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->v=v;
    t->next=a[u];
    a[u]=t;
}

int main()
{
    int i,e,u,v;
    scanf("%d%d",&n,&e);

    for(i=0;i<n;i++)
    {
        a[i]=NULL;
        in[i]=out[i]=0;
    }

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        out[u]++;
        in[v]++;
    }

    for(i=0;i<n;i++)
    {
        struct node *p=a[i];
        printf("%d->",i);
        while(p)
        {
            printf("%d->",p->v);
            p=p->next;
        }
        printf("NULL\n");
    }

    for(i=0;i<n;i++)
        printf("%d %d %d %d\n",i,in[i],out[i],in[i]+out[i]);

    return 0;
}

7) Kruskal MST

#include<stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}

void uni(int i,int j)
{
    parent[j]=i;
}

int main()
{
    int c[5][5]={
        {999,2,999,6,999},
        {2,999,3,8,5},
        {999,3,999,999,7},
        {6,8,999,999,9},
        {999,5,7,9,999}
    };

    int i,j,min,a,b,u,v,cost=0,e=0;

    while(e<4)
    {
        min=999;

        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
                if(c[i][j]<min)
                {
                    min=c[i][j];
                    a=u=i;
                    b=v=j;
                }

        u=find(u);
        v=find(v);

        if(u!=v)
        {
            printf("%d-%d=%d\n",a,b,min);
            cost+=min;
            uni(u,v);
            e++;
        }

        c[a][b]=c[b][a]=999;
    }

    printf("Minimum Cost=%d",cost);
    return 0;
}

8) BST Menu Driven (Insert Search Traversals)

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