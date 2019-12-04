#include<stdio.h>
#include<stdlib.h>
typedef struct element{
	int key;
}element;
struct list{
	element data;
	struct list *llink;
	struct list *rlink;
};

typedef struct list *listptr;

void insert(listptr head,int no){
	listptr node=(listptr)malloc(sizeof(struct list));
	node->data.key=no;
	node->rlink=head->rlink;
	head->rlink->llink=node;
	node->llink=head;
	head->rlink=node;
	return;
}

element delete(listptr head){
	listptr node=head->rlink;
	element item=node->data;
	node->rlink->llink=head;
	node->llink->rlink=node->rlink;
	free(node);
	return item;
}

void rdisplay(listptr head){
	listptr temp=head->rlink;
	for(;temp!=head;temp=temp->rlink)
		printf("%d ",temp->data.key);
	printf("\n");
}

void ldisplay(listptr head){
        listptr temp=head->llink;
        for(;temp!=head;temp=temp->llink)
                printf("%d ",temp->data.key);
        printf("\n");
}

void main(){
	int choice,no;
	element item;
	listptr head=(listptr)malloc(sizeof(struct list));
	head->data.key=-1;
	head->llink=head;
	head->rlink=head;
	while(1){
		printf("1-Insert  2-Delete  3-Forward Dispaly  4-Backward Dispaly  5-Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the element to be inserted.\n");
				scanf("%d",&no);
				insert(head,no);
				break;
			case 2:
				if(head->llink==head)
					printf("No elements\n");
				else{
					item=delete(head);
					printf("Element  deleted is %d.\n",item.key);
				}
				break;
			case 3:
				if(head->llink==head)
					printf("No elements.\n");
				else{
					printf("Forward Display\n");
					rdisplay(head);
				}
				break;
			case 4:
				if(head->llink==head)
                                        printf("No elements.\n");
                                else{
					printf("Backward Display\n");
					ldisplay(head);
				}
				break;
			case 5: 
				printf("----------Exiting----------\n");
				exit(0);
		}
	}
}



