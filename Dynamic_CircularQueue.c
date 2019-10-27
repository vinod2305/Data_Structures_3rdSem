#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int key;
}element;
int front=0,rear=0;
int capacity=1;
element *q, *nq;

int deleteq(){
        front=(front+1)%capacity;
        return (q[front].key);
}

void addq(){
int j,n;
if(front==((rear+1)%capacity))
{
	printf("Doubling the size of Queue to %d\n",2*capacity);
	nq=(element*)malloc(2*capacity*sizeof(element));
	for(j=0;j<capacity-1;j++)
		nq[j].key=deleteq();
	front=2*capacity-1;
	rear=capacity-2;
	capacity=2*capacity;
	free(q);
	q=nq;
}
rear=(rear+1)%capacity;
printf("Enter the element to be added to Queue\n");
scanf("%d",&n);
q[rear].key=n;
}

void display(){
	int i;
	printf("Queue elemets:");
	for(i=(front+1)%capacity;i!=(rear+1)%capacity;i=(i+1)%capacity)
		printf("%d ",q[i].key);
	printf("\n");
}

void main()
{
	int choice;
	q=(element*)malloc(1*sizeof(element));
	while(1){
		printf("1-Add 2-Remove 3-Display 4-exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addq();
				break;
			case 2:
				if(front==rear){
					printf("Queue is empty\n");
				}
				else
					printf("%d is deleted from Queue\n",deleteq());
					break;
			case 3:
					display();
					break;
			case 4:
					printf(".........Exiting.........\n");
					exit(0);
					break;
			default: 
					printf("Wrong choice\n");
		}
	}
}
				
