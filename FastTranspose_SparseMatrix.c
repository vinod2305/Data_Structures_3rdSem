#include<stdio.h>
#define MS 101
typedef struct{
        int col;
        int row;
        int value;
}term;
term a[MS];
term b[MS];
void fastTranspose(term a[],term b[]){
	int rowTerms[MS],startingPos[MS];
	int i,j,numCols=a[0].col,numTerms=a[0].value;
	b[0].row=numCols;
	b[0].col=a[0].row;
	b[0].value=numTerms;
	if(numTerms>0){
		for(i=0;i<numCols;i++)
			rowTerms[i]=0;
		for(i=1;i<=numTerms;i++)
			rowTerms[a[i].col]++;
		startingPos[0]=1;
		for(i=1;i<numCols;i++)
			startingPos[i]=startingPos[i-1]+rowTerms[i-1];
		for(i=1;i<=numTerms;i++){
			j=startingPos[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].value=a[i].value;
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
        fastTranspose(a,b);
        printf("\n------Transposed Matrix------\n");
        for(i=1;i<=b[0].value;i++)
        {
                printf("Value at %d Row and %d Column is %d\n",b[i].row,b[i].col,b[i].value);
      	}
}
