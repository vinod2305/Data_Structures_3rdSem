#include<stdio.h>
typedef enum{lparen,rparen,add,sub,mul,div,mod,eos,operand}precedance;

int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};

precedance stack[20];
char expr[20];
int top=0,n=0;
precedance pop(){
	return stack[top--];
}
void printtoken(precedance token){
       switch(token){
	       case add: printf("+");
			  break;
	       case sub: printf("-");
			 break;
		case mul: printf("*");
                         break;

		case div: printf("/");
                         break;

		case mod: printf("mod");
                         break;
       }

}
void push(precedance token){
	stack[++top]=token;
}
precedance getToken(char *symbol,int *n){
	*symbol=expr[(*n)++];
	switch(*symbol){
		case '+': return add;
		case '-': return sub;
		case '*': return mul;
		case '/': return div;
		case '%': return mod;
		case '\0': return eos;
		case '(': return lparen;
		case ')': return rparen;
		default: return operand;
	}
}

void cov()
{
	precedance token;
	char symbol;
	stack[0]=eos;
	for(token=getToken(&symbol,&n);token!=eos;token=getToken(&symbol,&n)){
		if(token==operand)
			printf("%c",symbol);
		else if(token==rparen){
				while(stack[top]!=lparen)
					printtoken(pop());
			pop();
		}
		else{
			while(isp[stack[top]]>=icp[token])
				printtoken(pop());
			push(token);
		}
	}
	while((token=pop())!=eos)
		printtoken(token);
	printf("\n");
}


void main(){
	printf("Enter Infix expression:\n");
	scanf("%s",expr);
	cov();
}


