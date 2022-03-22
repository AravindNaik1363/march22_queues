#include<stdio.h>
#include<stdlib.h>
typedef struct node//using typedef,queue as alias name 
{
  int data;
  struct node *next;
}queue;

void enqueue(int data,struct node **front,struct node **rear)//function definition for inserting elements in queue
{
  queue *newnode=malloc(sizeof(queue));
  if(newnode==NULL)
  {
    printf("memory not allocated\n");
  }
  else
  {
    newnode->data=data;
    newnode->next=NULL;
    
    if(*front==NULL && *rear==NULL)
    {
      *front=newnode;
      *rear=newnode;
    }
    else
    {
      (*rear)->next=newnode;
      (*rear)=newnode;
    }
    printf("enqueued element is:%d\n",(*rear)->data);
  }
}

void dequeue(queue **front)//function definition for deleting elements in queue
{
  if(*front==NULL)
  {
    printf("queue is empty\n");
  }
  else
  {
    queue *temp=*front;
    *front=temp->next;
    printf("\nDequeued element is:%d\t",temp->data);
    free(temp);
  }
}
    
void display(queue **front)//function definition for displaying elements in queue
{
  if(*front==NULL)
  {
    printf("\nqueue is empty");
  }
  else
  {
    printf("elements in queue are:\n");
    queue *temp=*front;
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->next;
    }
  }
  
}

int main() 
{
  struct node *front=NULL;
  struct node *rear=NULL;
  enqueue(10,&front,&rear);
  enqueue(20,&front,&rear);
  enqueue(30,&front,&rear);
  display(&front);
  dequeue(&front);
  dequeue(&front);
  dequeue(&front);
  display(&front);

  return 0;
}
