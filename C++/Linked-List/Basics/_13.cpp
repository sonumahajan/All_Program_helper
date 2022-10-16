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

void efficMiddle(node *head)
{
    // using slow and fast pointers approach
    while(head==NULL)
    return;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL) //fast not null for even, fast next not null for odd
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
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
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    printList(head);
    cout<<endl;
    efficMiddle(head);
    return 0;
}