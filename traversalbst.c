/*program for traversal of BST*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*lchild;
	struct node*rchild;
};
struct node*insert(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int count_nodes(struct node*);
struct node*root=NULL;
int main(){
	int choice,item;
	while(1){
		printf("\n....MENU....\n");
		printf("1.insert\n2.inorder\n3.preorder\n4.postorder\n5.count_nodes\n.6.exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter element:");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:if(root==NULL)
				printf("tree is empty\n");
				else{
					printf("inorder traversal\n");
					inorder(root);
				}
				break;
			case 3:if(root==NULL)
				printf("tree is empty\n");
				else{
					printf("preorder traversal\n");
					preorder(root);
				}
				break;
			case 4:if(root==NULL)
				printf("root is empty\n");
				else{
					printf("post order traversal\n");
					postorder(root);
				}
				break;
			case 5:count_nodes(root);
				break;
			case 6:exit(0);
		}
	}
}
struct node*insert(struct node*root,int item){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=item;
		root->lchild=NULL;
		root->rchild=NULL;
	}
	else if(item <root->data)
		root->lchild=insert(root->lchild,item);
	else
		root->rchild=insert(root->rchild,item);
	return root;
}
void inorder(struct node*root){
	if(root!=NULL){
		inorder(root->lchild);
		printf("%4d",root->data);
		inorder(root->rchild);
	}
}
void preorder(struct node*root){
	if(root!=NULL){
		printf("%4d",root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void postorder(struct node*root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%4d",root->data);
	}
}
int count_nodes(struct node*root){
	if(root==NULL)
		return 0;
	else
		return 1+count_nodes(root->rchild)+count_nodes(root->lchild);
}
