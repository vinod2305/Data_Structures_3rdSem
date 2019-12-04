#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (x>y)?1:((x<y)?-1:0)
struct node{
	int coef;
	int expo;
	struct node *link;
};
typedef struct node *polyptr;

void attach(int coef,int expo,polyptr *ptr){
        polyptr temp=(polyptr)malloc(sizeof(struct node));
        temp->coef=coef;
        temp->expo=expo;
        (*ptr)->link=temp;
        (*ptr)=temp;
       
}


polyptr padd(polyptr a,polyptr b){
	int sum,done=0;
	polyptr c,startA,lastC;
	startA=a;
	a=a->link;
	b=b->link;
	c=(polyptr)malloc(sizeof(struct node));
	c->expo=-1;
	lastC=c;
	do{
		switch(COMPARE(a->expo,b->expo)){
			case 1:
				attach(a->coef,a->expo,&lastC);
				a=a->link;
				break;
			case -1:
				attach(b->coef,b->expo,&lastC);
				b=b->link;
				break;
			case 0:
				if(startA==a)
					done=1;
				else{
					sum=a->coef+b->coef;
					if(sum){
						attach(sum,a->expo,&lastC);
						a=a->link;
						b=b->link;
					}
				}
				break;
			}
	}while(!done);
	lastC->link=c;
	return c;
}

void main(){
	polyptr a,b,c,t,t1;
	int m,n,i,expo,coef;
	printf("Enter the number of terms in first and second ptr\n");
	scanf("%d%d",&m,&n);
	a=(polyptr)malloc(sizeof(struct node));
	b=(polyptr)malloc(sizeof(struct node));
	a->expo=-1;
	b->expo=-1;
	t1=a;
	printf("Enter the coeff and expo of first polynomial\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&coef,&expo);
		attach(coef,expo,&t1);
	}
	t1->link=a;
	t1=b;
	printf("Enter the coeff and expo of second polynomial\n");
        for(i=0;i<n;i++){
                scanf("%d%d",&coef,&expo);
                attach(coef,expo,&t1);
        }
        t1->link=b;
	c=padd(a,b);
	t=c;
	printf("Resultant polynomial is:\n");
	for(t=t->link;t->link!=c;t=t->link)
		printf("%d^%d+",t->coef,t->expo);
	printf("%d^%d",t->coef,t->expo);
	printf("\n");
}

