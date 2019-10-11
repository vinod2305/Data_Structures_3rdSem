#include<stdio.h>
int fib(int n);

void main(){
	int n,i=0,c;
	printf("Enter a number to generate Fibonacci series.\n");
	scanf("%d",&n);
	printf("Fibonacci series terms are:\n");
	for(c=1;c<=n;c++)
	{
		printf("%d\t",fib(i));
		i++;
	}
	printf("\n");
}

int fib(int n){
	if(n==1 || n==0)
		return n;
	else
		return (fib(n-1)+fib(n-2));
}

