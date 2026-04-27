// prims mst

#include<stdio.h>
#define MAX 20
#define INF 999

int cost[MAX][MAX], visited[MAX];

int main()
{
    int n, e, i, j, v1, v2, w;
    int min, a, b, u, v, ne = 1;
    int mincost = 0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter number of edges: ");
    scanf("%d",&e);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cost[i][j] = INF;

    for(i=1;i<=e;i++)
    {
        printf("Enter edge (v1 v2 weight): ");
        scanf("%d%d%d",&v1,&v2,&w);

        cost[v1-1][v2-1] = w;
        cost[v2-1][v1-1] = w;
    }

  
    printf("\nAdjacency Matrix (Cost Matrix):\n\n        ");
    for(i=0;i<n;i++)
        printf("%5d",i+1);
    printf("\n   ");

    for(i=0;i<n;i++)
    {
        printf("%5d",i+1);

        for(j=0;j<n;j++)
        {
            if(i==j)
                printf("%5d",0);
            else
                printf("%5d",cost[i][j]);
        }
        printf("\n   ");
    }

    for(i=0;i<n;i++)
        visited[i] = 0;

    visited[1] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(ne < n)
    {
        min = INF;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("%d edge (%d,%d) = %d\n",ne++,a,b,min);
            mincost = mincost + min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\n Minimum Cost = %d\n",mincost);

    return 0;
}


/*
Output
cc prims1.c
sy57@Lab2-Pc10-hptrykcs:~/Desktop/sy57sem4/DS-2$ ./a.out
Enter number of vertices: 5
Enter number of edges: 6
Enter edge (v1 v2 weight): 1 3 3
Enter edge (v1 v2 weight): 2 3 10
Enter edge (v1 v2 weight): 2 4 4
Enter edge (v1 v2 weight): 2 5 1
Enter edge (v1 v2 weight): 3 4 2
Enter edge (v1 v2 weight): 3 5 6

Adjacency Matrix (Cost Matrix):

            1    2    3    4    5
       1    0  999    3  999  999
       2  999    0   10    4    1
       3    3   10    0    2    6
       4  999    4    2    0  999
       5  999    1    6  999    0
   
Edges in Minimum Spanning Tree:
1 edge (1,4) = 1
2 edge (1,3) = 4
3 edge (3,2) = 2
4 edge (2,0) = 3

 Minimum Cost = 10

*/
