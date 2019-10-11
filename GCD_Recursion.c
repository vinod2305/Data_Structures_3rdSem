#include<stdio.h>
#include<ctype.h>
int gcd(int a,int b);

void main(){
	int gcdResult,a,b;
	printf("Enter two numbers to find GCD:\n");
	scanf("%d%d",&a,&b);
	gcdResult= gcd(a,b);
	printf("GCD of %d and %d is %d\n",a,b,gcdResult);
}

int gcd(int a,int b){
	if(b==0)
		return a;
	if(a==0)
		return b;
	return gcd(b,a%b);
}	

