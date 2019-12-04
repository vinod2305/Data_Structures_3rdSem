#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *rlink;
	struct node *llink;
};
typedef struct node *ptr;

void insert(ptr *root,int key){
	if(*root==NULL){
		*root=(ptr)malloc(sizeof(struct node));
		(*root)->rlink=NULL;
		(*root)->llink=NULL;
		(*root)->data=key;
	}
	else if(key>((*root)->data))
		insert(&(*root)->rlink,key);
	else
		insert(&(*root)->llink,key);
}

int search(ptr root,int key){
	if(root==NULL)
		return 0;
	else if(key==root->data)
                return 1;
	else if(key>root->data)
		search(root->rlink,key);
	else
		search(root->llink,key);
}

void inorder(ptr root){
	if(root){
		inorder(root->llink);
		printf("%d\n",root->data);
		inorder(root->rlink);
	}
}

void main(){
int key,choice;
ptr root;
root=NULL;
	while(1){
		printf("1-Insert  2-Search  3-InOrder Display  4-Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the element to be inserted.\n");
				scanf("%d",&key);
				insert(&root,key);
				break;
			case 2:
				printf("Enter the element to be searched.\n");
				scanf("%d",&key);
				if(search(root,key))
					printf("%d FOUND in BST.\n",key);
				else
					printf("%d NOT FOUND.\n",key);
				break;
			case 3:
				printf("InOrder traversal of BST:\n");
				inorder(root);
				break;
			case 4:
				printf("---------Exiting----------\n");
				exit(0);
		}
	}
}
