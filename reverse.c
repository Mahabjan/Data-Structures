#include<stdio.h>
#include<stdlib.h>
#define MAX 20
struct node
{
	int data;
	struct node*next;
};
 void creat();
 void display();
 void reverse();
 void push(int);
 int pop();
 struct node*head=NULL;
 int top=-1,stack[MAX];
 int main()
 {
	creat();
	display();
	printf("\n");
	printf("list after reversal\n");
	reverse();
	display();
	return 0;
}
void creat()
{
	struct node*cur,*temp;
	int choice=1,item;
	while(choice==1)
	 {
	  	printf("Enter the element\n");
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
	    	printf("DO YOU WANT TO CONTINE:");
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
  	   printf("list content\n");
  	  while(temp!=NULL)
  	  {
  	     printf("%4d",temp->data);
  	      temp=temp->next;
  	   }
  	}
  }
  void reverse()
  {
  	struct node*cur=head; 
  	while(cur!=NULL)
  	{
  	 push(cur->data);
  	 cur=cur->next;
  	 }
  	 cur=head;
  	 while(cur!=NULL)
  	 {
  	  cur->data=pop();
  	   cur=cur->next;
  	 }
  }
  void push(int item)
{
    if(top==MAX-1)
        printf("Stack OVERFLOW\n");
    else
    {
        top++;
        stack[top]=item;
    }
}

int pop()
{
    if(top==-1)
        printf("Stack underflow\n");
    else
    {
        int item=stack[top];
        top--;
        return item;
    }
}
   
   
  	
