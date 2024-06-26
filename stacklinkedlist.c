#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
typedef struct node NODE;
void insert_front(int);
void delete_front();
void display();
NODE*head=NULL;
int main()
{
    int choice,item;
    while(1)
    {
      printf("\nMENU\n");
      printf("\n1.Push\n");
      printf("\n2.Pop\n");
      printf("\n3.Display\n");
      printf("\n4.Exit(0)\n");
      printf("enter your choice:\n");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:printf("enter the element to be inserted:\n");
               scanf("%d",&item);
               insert_front(item);
               break;
        case 2:delete_front();
               break;
        case 3:display();
               break;
        case 4:exit(0);
        default:printf("invalid choice\n");
      }
    }
}
void insert_front(int item)
{
      NODE*temp;
      temp=(NODE*)malloc(sizeof(NODE));
      temp->data=item;
      temp->next=head;
      head=temp;
}
void delete_front()
{
      NODE*temp;
      if(head==NULL)
         printf("list is empty\n");
      else
      {
         temp=head;
         head=head->next;
         printf("element deleted:\n",temp->data);
         free(temp);
      }
}
void display()
{
      NODE*temp=head;
      if(head==NULL)
         printf("list is empty:\n");
      else
     {
         printf("list content:\n");
         while(temp!=NULL)
         {
              printf(" %d",temp->data);
              temp=temp->next;
         }
     }
}


