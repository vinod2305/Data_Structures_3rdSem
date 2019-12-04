#include<stdio.h>
#include<stdlib.h>
typedef struct element{
	int key;
}element;
struct stack{
	element data;
	struct stack *link;
};
typedef struct stack *listptr;
listptr top[100];

void push(element item,int i){
	listptr temp;
	temp=(listptr)malloc(sizeof(struct stack));
	temp->data=item;
	if(!top[i]){
		top[i]=temp;
	}
	else{
		temp->link=top[i];
		top[i]=temp;
	}
}

element pop(int i){
	listptr temp=top[i];
	element item;
	if(!temp){
		item.key=-1;
		return item;
	}
	item=temp->data;
	top[i]=temp->link;
	free(temp);
	return item;
}

void display(int i){
	listptr temp=top[i];
	if (top[i]==NULL) {
		printf("stack is empty\n");
		return;
	}
	printf("stack %d is\n",i);
	for(;temp;temp=temp->link)
		printf("%d ",temp->data.key);
	printf("/n");
}

void main(){
	int choice,stackno,no;
	element item;
	while(1){
		printf("enter 1-Push 2-Pop 3-Dispaly 4-Exit\n");
		scanf("%d",&choice);
		if(choice!=4) {
			printf("Enter stack number from 1-10\n");
			scanf("%d",&stackno);
		}
		switch(choice){
			case 1:
				printf("Enter the element to be inserted.\n");
				scanf("%d",&no);
				item.key=no;
				push(item,stackno);
				break;
			case 2:
				item=pop(stackno);
				if(item.key==-1)
					printf("Empty stack\n");
				else
					printf("%d poped\n",item.key);
				break;
			case 3:
				display(stackno);
				break;
			case 4:
				printf("----------Exiting----------\n");
				exit(0);
		}
	}
}

