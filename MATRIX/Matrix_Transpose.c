#include<stdio.h>
int main()
{
	int i,j,a[5][5],b[5][5];
	printf("enter the elements in matrix a");
	for(i=0;i<5;i++)
	{
	for(j=0;j<5;j++)
	{
		scanf("%d",&a[i][j]);}
	
	}
	printf(" the first matrix is :\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	printf("the second matrix is:\n");
	for( i=0;i<5;i++)
	{
		for( j=0;j<5;j++)
		{
			printf(" %d ",a[j][i]);
		}
		printf("\n");
	}
	return 0;
}
