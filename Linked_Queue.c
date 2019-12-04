#include<stdio.h>
#include<stdlib.h>
typedef struct element{
	int key;
}element;
struct queue{
	element data;
	struct queue *link;
};
typedef struct queue *queueptr;
queueptr front[100], rear[100];

void addq(element item,int i){
	queueptr temp=(queueptr)malloc(sizeof(struct queue));
	temp->data=item;
	if(!front[i])
		front[i]=temp;
	else
		rear[i]->link=temp;
	rear[i]=temp;
}

element deleteq(int i){
	queueptr temp=front[i];
	element item;
	if(!front[i]){
		item.key=-1;
		return item;
	}
	item=temp->data;
	front[i]=temp->link;
	free(temp);
	return item;
}

void display(int i){
	queueptr temp=front[i];
	if (front[i]==NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("Elements of QueueNo%d:\n",i);
	for(;temp;temp=temp->link)
		printf("%d ",temp->data.key);
	printf("\n");
}

void main(){
	int choice,queueno;
	element item;
	while(1){
		printf("Enter 1-Add 2-Delete 3-Dispaly 4-Exit\n");
		scanf("%d",&choice);
		if(choice!=4) {
			printf("Enter queue number from 1-10\n");
			scanf("%d",&queueno);
		}
		switch(choice){
			case 1:
				printf("Enter the element to be inserted\n");
				scanf("%d",&item.key);
				addq(item,queueno);
				break;
			case 2:
				item=deleteq(queueno);
				if(item.key==-1)
					printf("Empty queue\n");
				else
					printf("%d deleted from queue %d\n",item.key,choice);
				break;
			case 3:
				display(queueno);
				break;
			case 4:
				printf("---------Exiting---------\n");
				exit(0);
		}
	}
}

		

