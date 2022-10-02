#include<iostream>

using namespace std;

typedef struct queue
{
int data;
struct queue *next;
}node;

node *front = NULL;
node *rear = NULL;

int qempty()
{
if(front == NULL && rear == NULL)
return 1;
else
return 0;
}

void addq()
{
// Create a node with data and next as NULL
node *new1 = new node;
cout << "Enter no:" << endl;
cin >> new1->data;
new1->next = NULL;

if(front == NULL && rear == NULL)
{
front = new1;
rear = new1;
}
else
{
rear->next = new1;
rear = new1;
}
}
void delq()
{
int no;

// Find out if queue is empty
if(qempty() == 1)
cout << "Queue is Empty" << endl;
else
{
rear = front;
no = rear->data;
cout << "Deleted no is:" << no << endl;
front = front->next;

// delete the element that front is pointing to
delete(rear);
}
}
void disq()
{
// Find out if queue is empty
if(qempty() == 1)
cout << "Queue is Empty" << endl;
else
{
rear = front;
while(rear != NULL)
{
cout << rear->data << " ";
rear = rear->next;
}
}
}
int main()
{
int ch;
char ans;
do
{
cout << "1: Add 2: Delete 3: Display" << endl;
cout << "Enter your choice:" << endl;
cin >> ch;

switch(ch)
{
case 1: addq();
break;
case 2: delq();
break;
case 3: disq();
break;
}
cout << "Do you want to continue: y or n:" << endl;
cin >> ans;
}while(ans == 'y');

return 0;
}
