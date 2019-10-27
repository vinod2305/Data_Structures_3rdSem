#include<stdio.h>
#include<string.h>
void fail(char *pat);
int pmatch(char *pat,char *str);
int failure[20];
int i,j;
void main(){
	char str[20],pat[20];
	int ans=0;
	printf("Enter the string\n");
	scanf("%s",str);
	printf("Enter the pattern to be matched\n");
	scanf("%s",pat);
	fail(pat);
	ans=pmatch(pat,str);
	printf("Pattern found at position : %d\n",ans+1);
}


void fail(char *pat)
{
	int n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++){
		i=failure[j-1];
		while(pat[j]!=pat[i+1]&&i>=0)
			i=failure[i];
		if(pat[j]==pat[i+1])
			failure[j]=i+1;
		else
			failure[j]=-1;
		}
}
int pmatch(char *pat,char *str)
{
	int lens=strlen(str);
	int lenp=strlen(pat);
	int i=0,j=0;
	while(i<lens&&j<lenp){
		if(str[i]==pat[j]){
			i++;
			j++;
		}
		else if(j==0)
			i++;
		else
			j=failure[j-1]+1;
	}
	return (j==lenp)? (i-lenp): -1;
}
