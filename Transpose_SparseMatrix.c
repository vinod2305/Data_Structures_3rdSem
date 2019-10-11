#include<stdio.h>
#define MS 101
typedef struct{
	int col;
	int row;
	int value;
}term;
term a[MS];
term b[MS];
void transpose(term a[],term b[]){
	int i,j,currentb,n=a[0].value;
	b[0].col=a[0].row;
	b[0].row=a[0].col;
	b[0].value=n;
	if(n>0){
		currentb=1;
		for(i=0;i<a[0].col;i++)
			for(j=1;j<=n;j++)
				if(a[j].col==i)
				{
					b[currentb].col=a[j].row;
					b[currentb].row=a[j].col;
					b[currentb].value=a[j].value;
					currentb++;
				}
	}
}
void main()
{
	int i;
	printf("Enter the number of rows and columns of the matrix:");
	scanf("%d%d",&a[0].row,&a[0].col);
	printf("Enter the number of non zero elements in sparse martix: ");
	scanf("%d",&a[0].value);
	for(i=1;i<=a[0].value;i++)
	{
		printf("Enter the Row value: ");
		scanf("%d",&a[i].row);
		printf("Enter the Column value: ");
                scanf("%d",&a[i].col);
		printf("Enter the value at %d Row and %d Column: ",a[i].row,a[i].col);
                scanf("%d",&a[i].value);
	}
	transpose(a,b);
	printf("\n------Transposed Matrix------\n");
	for(i=1;i<=b[0].value;i++)
	{
                printf("Value at %d Row and %d Column is %d\n",b[i].row,b[i].col,b[i].value);
	}
}
