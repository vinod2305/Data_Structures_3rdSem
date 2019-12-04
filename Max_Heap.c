#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct{
	int key;
}element;
element heap[MAX_SIZE];
int n=0;

void insert(element item){
	int i;
	i=++n;
	if(n==MAX_SIZE-1){
		printf("HEAP is full\n");
		return;
	}
	while(i!=1 && item.key>heap[i/2].key){
		heap[i]=heap[i/2];
		i=i/2;
	}
	heap[i]=item;
}

element pop(){
	int child,parent;
	element item,temp;
	if(n==0){
		printf("HEAP is EMPTY\n");
		item.key=-1;
		return item;
	}
	item=heap[1];
	temp=heap[n--];
	parent=1;
	child=2;
	while(child<=n){
		if(child<n && heap[child].key<heap[child+1].key)
			child++;
		if(heap[child].key<temp.key)
			break;
		heap[parent]=heap[child];
		parent=child;
		child=child*2;
	}
	heap[parent]=temp;
	return item;
}

void display(){
	int i;
	printf("HEAP elements are:\n");
	for(i=1;i<=n;i++)
		printf("%d ",heap[i].key);
	printf("\n");
}
void main(){
	int choice;
	element item;
	while(1){
		printf("1-Insert 2-Delete 3-Display 4-Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the element to be inserted.\n");
				scanf("%d",&item.key);
				insert(item);
				break;
			case 2:
				item=pop();
				if(item.key!=-1)
				printf("Deleted %d from the HEAP.\n",item.key);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("---------Exiting---------\n");
				exit(0);
			}
	}
}


