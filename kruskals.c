 Kruskal MST

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

