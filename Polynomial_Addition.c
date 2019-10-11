#include<stdio.h>
#define COMPARE(x,y) (x<y)?-1:(x>y)?1:0
void attach(int,int);
typedef struct{
	int coef;
	int expo;
}poly;
poly terms[100];
int avail=0;
void add(int sa,int fa,int sb,int fb,int *sd,int *fd){
	int sum;
	*sd=fb+1;
	while((sa<=fa)&&(sb<=fb)){
		switch(COMPARE(terms[sa].expo,terms[sb].expo))
		{
			case 1:
				attach(terms[sa].coef,terms[sa].expo);
				sa++;
				break;
			case -1:
				attach(terms[sb].coef,terms[sa].expo);
				sb++;
				break;
			case 0:
				sum=terms[sa].coef+terms[sb].coef;
				if(sum)
					attach(sum,terms[sa].expo);
				sa++;
				sb++;
				break;
		}
	}
	for(;sa<=fa;sa++)
		attach(terms[sa].coef,terms[sa].expo);
	for(;sb<=fb;sb++)
		attach(terms[sb].coef,terms[sb].expo);
	*fd=avail-1;
}
void attach(int coef,int expo){
	terms[avail].coef=coef;
	terms[avail++].expo=expo;
}
void main(){
	int sa,sb,fa,fb,sd,fd,m,n,i;
	printf("Enter the number of terms in 1st equation.\n");
	scanf("%d",&m);
	printf("Enter the number of terms in 2nd equation.\n");
	scanf("%d",&n);
	sa=0;
	fa=m-1;
	sb=m;
	fb=m+n-1;
	printf("enter the coefficients and exponents of the first equation.\n");
	for(i=sa;i<=fa;i++)
		scanf("%d%d",&terms[i].coef,&terms[i].expo);

	printf("First equation:\n");
	for(i=sa;i<fa;i++)
                printf("%dX^%d+",terms[i].coef,terms[i].expo);
	printf("%dX^%d\n",terms[fa].coef,terms[fa].expo);
	
	printf("enter the coefficients and exponents of the second equation.\n");
	for(i=sb;i<=fb;i++)
		scanf("%d%d",&terms[i].coef,&terms[i].expo);

	printf("Second equation:\n");
        for(i=sb;i<fb;i++)
                printf("%dX^%d+",terms[i].coef,terms[i].expo);
        printf("%dX^%d\n",terms[fb].coef,terms[fb].expo);
	
	avail=fb+1;
	add(sa,fa,sb,fb,&sd,&fd);
	
	printf("Resulant equation:\n");
	for(i=sd;i<fd;i++)
		printf("%dX^%d+",terms[i].coef,terms[i].expo);
	printf("%dX^%d\n",terms[fd].coef,terms[fd].expo);
}
