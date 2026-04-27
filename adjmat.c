#include<stdio.h>
int main()
{
   int n,e,adj[20][20],i,j,v1,v2,d[20];
   
   printf("\nEnter the number of vertices: ");
   scanf("%d",&n);
   
   if (n<=0 || n>20)
   {
      printf("\nInvalid number of vertices");
      return 0;
   }

   printf("\nEnter the number of edges: ");
   scanf("%d",&e);
   
   for (i=0;i<n;i++)
   {
       d[i]=0;
       for(j=0;j<n;j++)
       {
           adj[i][j]=0;
       }
   }

   for (i=1;i<=e;i++)
   {
        printf("\nEnter the Edge (v1 v2): ");
        scanf("%d%d",&v1,&v2);
        
        if (v1 < 1 || v1 > n || v2 < 1 || v2 > n)
        {
           printf("\nInvalid edge");
           i--;
           continue;
        }

        adj[v1-1][v2-1]=1;
        adj[v2-1][v1-1]=1;
    }

    printf("\nAdjacency Matrix for Undirected Graph with Degree:\n     ");
    for (i=0;i<n;i++)
        printf("%5d",i+1); 

    printf("    Total Degree\n");    

    for (i=0;i<n;i++)
    {
        printf("%5d",i+1);  
        for(j=0;j<n;j++)
        {
              if (adj[i][j]==1)
                 d[i]++; 
              printf("%5d",adj[i][j]);
        }
       printf("%12d\n",d[i]);
    }

    return 0;
}
