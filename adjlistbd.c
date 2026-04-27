Adjacency List + BFS + DFS

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

