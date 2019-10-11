#include<stdio.h>
char expr[20];
int top;
int stack[10];
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

void push(int x){
        stack[++top]=x;
}
int pop(){
        return stack[top--];
}

precedence getToken(char *symbol, int *n){
        *symbol=expr[(*n)++];
        switch(*symbol){
                case '+': return plus;
                case '-': return minus;
                case '*': return times;
                case '/': return divide;
                case '%': return mod;
		case ';': return eos;
                default: return operand;
        }
}


int eval(){
	int n=0;
	top=-1;
	precedence token;
	char symbol;
	int op1,op2;
	token=getToken(&symbol,&n);
	while(token!=eos){
		if(token==operand)
			push(symbol-'0');
		else{
			op2=pop();
			op1=pop();
		
			switch(token){
				case plus:
					push(op1+op2);
					break;
				case minus:
					push(op1-op2);
					break;
				case times:
					push(op1*op2);
					break;
				case divide:
					push(op1/op2);
					break;
				case mod:
					push(op1%op2);
					break;
			}
		}		
		token=getToken(&symbol,&n);
	}
	return pop();
}



void main()
{
	int result;
	printf("Enter postfix expression ending with %c\n",59);
	scanf("%s",expr);
	result=eval();
	printf("Result is %d\n",result);
}
