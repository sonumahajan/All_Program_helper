#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  char name[256];
  struct Queue *next;
}
*start=NULL;

void Enqueue()
{
  struct Queue *q, *temp;
  q=(struct Queue*)malloc(sizeof (struct Queue));
  printf("\nEnter the Name of the Task:");
  scanf("%s",&q->name);
  if(start==NULL)
  {
    start=q;
  }
  else
  {
    temp=start;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=q;
  }
}

void Dequeue()
{
  struct Queue *q, *temp;
  if(start==NULL)
  {
    printf("\nYour list of Tasks are Empty");
  }
  else
  {
    temp=start;
    printf("\nRemoved %s from your List of Tasks\n",temp->name);
    start=start->next;
    free(temp);
  }
}

void Display_One()
{
  struct Queue *q, *temp;
  temp=start;
  printf("\nThe task is %s\n",temp->name);
}

void Display()
{
  int i=0;
  struct Queue *q, *temp;
  temp=start;
  while(temp->next!=NULL)
  {
    i=i+1;
    printf("\nTask %d:%s",i,temp->name);
    temp=temp->next;
  }
  i=i+1;
  printf("\nTask %d:%s\n",i,temp->name);
}

int main()
{
  int User_Choice=1000;
  while(User_Choice!=0)
  {
    printf("\nList of Functions :\n 0: To exit \n 1: To Add a Task to the Task List \n 2: To Delete the First Task in the Task List \n 3: To Display the First Task in the Task List \n 4: To Display all Tasks in the Task List \n \n Type here: ");
    scanf("%d",&User_Choice);
    switch(User_Choice)
    {
      case 0:
        printf("\nThank you for your time!!!");
        break;
      case 1:
        Enqueue();
        break;
      case 2:
        Dequeue();
        break;
      case 3:
        Display_One();
        break;
      case 4:
        Display();
        break;
      default:
        printf("\nInvalid value entered, please try again!!!");
        break;
    }
  }
}