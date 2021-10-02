#include <iostream>
using namespace std;

#define size 5

class Queue

{

public:

int rear, front;

int ele;

int q[size];

Queue()

{

rear = -1;

front =0;

}

void Insert_Q();

void Delete_Q();

void Display_Q();

};

void Queue::Insert_Q()

{

cout << "Input Queue Element:";

cin>> ele;


if(rear ==size-1)

cout << "Queue is Full\n";

else

{

rear++;

q[rear] = ele;

}

}

void Queue::Delete_Q()

{



if(front > rear)

{

cout << "Queue is Empty. Nothing to Delete!" << endl;

}

else

{

ele = q[front];

cout << "Element that will be Deleted :" << ele << endl;

front = front + 1;

}

}

void Queue::Display_Q()

{

if(front >rear)

cout<<"Q empty";

for(int i=front;i<=rear;i++)

{

cout << " " << q[i];

}

cout << "\n\n";

}

int main()

{

Queue Q;

int choice;

char ch;

do

{

cout <<"1: Insert  2: Delete  " << endl;

cout <<"Enter your desired choice:"<< endl;

cin >> choice;

switch(choice)

{

case 1:

Q.Insert_Q( );

cout <<"Queue that will be after Insertion:";

Q.Display_Q ();

break;

case 2:

Q.Delete_Q();

cout <<"Queue that will be after Deletion"<< endl;

Q.Display_Q();

break;

}

cout<<"Do you want to continue(y/n)";

cin>> ch;

}while(ch=='y');

return 0;

}
