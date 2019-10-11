#include<stdio.h>
int fact(int n);
void main(){
	int n;
	printf("Enter a number to find factorial:\n");
	scanf("%d",&n);
	if(n<0)
		printf("Factorial of negative number cannot to found.\n");
	else
		printf("Factorial of %d is %d.\n",n,fact(n));
}

int fact(int n){
	if(n==1 || n==0)
		return 1;
	else
		return(n*fact(n-1));
}


