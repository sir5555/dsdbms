Adjacency List + Indegree Outdegree

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
