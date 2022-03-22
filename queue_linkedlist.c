#include<stdio.h>
#include<stdlib.h>//header file for malloc function
typedef struct node//using typedef,queue as alias name 
{
  int data;
  struct node *next;//self-referential structure
}queue;

void enqueue(int data,struct node **front,struct node **rear)//function definition for inserting elements in queue
{
  queue *newnode=malloc(sizeof(queue));//allocating memory to newnode on heap 
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
    printf("\nenqueued element is:%d\n",(*rear)->data);
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
    queue *temp=*front;//creating a temporary variable and assigning starting node address so we may not disturb first node and loose starting node address
    *front=temp->next;
    printf("\nDequeued element is:%d\t",temp->data);
    free(temp);//freeing the memory allocated to temp pointer so node that is pointed by temp is deleted
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
    printf("\nelements in queue are:\n");
    queue *temp=*front;//creating a temporary variable and assigning starting node address so we may not disturb first node and loose starting node address
    while(temp!=NULL)
    {
      printf("%d\t",temp->data);
      temp=temp->next;
    }
  }
  
}

int main() 
{
  struct node *front=NULL;//front pointer stores address of starting node and used while dequeing and displaying
  struct node *rear=NULL;//rear pointer is used to traverse the whole queue and used while enqueuing
  display(&front);//initially nothing is there in queue so prints empty queue
  enqueue(1,&front,&rear);//function call for inserting element in queue
  display(&front);
  enqueue(2,&front,&rear);
  display(&front);
  enqueue(3,&front,&rear);
  display(&front);
  dequeue(&front);//function call to delete element from queue
  display(&front);
  dequeue(&front);
  display(&front);
  dequeue(&front);
  display(&front);

  return 0;
}
