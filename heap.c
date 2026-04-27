
#include<stdio.h>
void swap(int a[],int j)
{
	int temp;
	temp=a[1];
	a[1]=a[j];
	a[j]=temp;
}

void buildheap(int a[],int i,int j)
{
	int c,temp,k;
	for (c=i+1;c<=j;c++)
	{
		k=c;
		while(k>1 && a[k]>a[k/2])
		{
			temp = a[k/2];
			a[k/2]=a[k];
			a[k]=temp;
			k=k/2;
		}
	}
}

void main()
{
        int n,i =1;
	printf("Enter the number of elements to sort : ");
	scanf("%d",&n);
	int a[n];
	a[0]=0;

	printf("Enter the tree to sort:");
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);

	printf("\n");
	printf("Original Data : ");
	for (i=1;i<=n;i++)
		printf("%4d",a[i]);

	buildheap(a,1,n);

	printf("\n");
        printf(" MAX heap : ");
	for (i=1;i<=n;i++)
		printf("%4d",a[i]);

	for(i=n;i>1;i--)
	{
		swap(a,i);
		buildheap(a,1,i-1);
	}
	printf("\n");
	printf("Sorted Data(Ascending) : ");
	for (i=1;i<=n;i++)
		printf("%4d",a[i]);
	printf("\n");

}
/*
Enter the number of elements to sort : 7
Enter the tree to sort:34
94
64
54
84
74
24

Original Data :   34  94  64  54  84  74  24
 MAX heap :   94  84  74  34  54  64  24
Sorted Data(Ascending) :   24  34  54  64  74  84  94
*/

