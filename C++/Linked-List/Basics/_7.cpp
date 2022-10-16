#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};

node *insertEnd(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    return temp; //returning temp, as we want to create a list, and head points to this 1st and only node
    node *current=head;
    while(current->next!=NULL) //if we write current!=null, then it will again go to loop and assign null to current
    {
        current=current->next;
    }
    current->next=temp;
    return head;
}

void printList(node *head)
{
    node *cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur=cur->next;
    }
}

int main()
{
    node *head=NULL;
    head=insertEnd(head,10);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    printList(head);
    return 0;
}