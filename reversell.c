#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
void create();
void display();
void reverse();
struct node*head=NULL;
int main()
{	
	create();
	printf("list before reversal\n");
	display();printf("\n");
	printf("list after reversal\n");
	reverse();
	
	display();
}
void create()
{
	struct node*cur,*temp;
	int choice=1,item;
	while(choice==1)
	{
		printf("Enter element\n");
		scanf("%d",&item);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=item;
		if(head==NULL)
		    head=cur=temp;
		else
		{
		  cur->next=temp;
		  cur=temp;
		}
		printf("Do you want to continue:");
		scanf("%d",&choice);
	}
	cur->next=NULL;
}
void display()
{
	struct node*temp=head;
		if(head==NULL)
		   printf("list empty\n");
		else
		{
			  while(temp!=NULL)
			  {
			  printf("%4d",temp->data);
			  temp=temp->next;
			  }
	        }
	
}
void reverse()
{
	struct node*prev=NULL,*nextnode=NULL,*cur=head;
	while(cur!=NULL)
	{	
		nextnode=cur->next;
		cur->next=prev;
		prev=cur;
		cur=nextnode;
	}

	head=prev;
}
	
