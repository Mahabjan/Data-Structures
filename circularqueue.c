/*Implementation of circulr queue*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int);
void delete();
void display();
int main(){
	int item,choice;
	while(1){
		printf("\n...MENU..\n");
		printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
		printf("enter your choice: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter the element:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:delete();
				break;
			case 3:display();
				break;
			case 4:exit(0);
		 	default:printf("invlid choice");
		}
	}
}
void insert(int item){
	if((rear+1)%MAX==front)
		printf("Q is FULL\n");
	else{
		rear=(rear+1)%MAX;
		queue[rear]=item;
		if(front==-1) front=0;
	}
}
void delete(){
	if(front==-1)
		printf("QUEUE IS EMPTY\n");
	else{
		printf("%d",queue[front]);
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%MAX;
	}
}
void display(){
	int i=front;
	if(front==-1)
		printf("queue is empty\n");
	else{
		while(i!=rear){
			printf("%4d",queue[i]);
			i=(i+1)%MAX;
		}
		printf("%4d",queue[rear]);
	}
}
