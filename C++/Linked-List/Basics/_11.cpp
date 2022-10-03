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

node *sortedInsert(node *head,int x)
{
    node *temp=new node(x);
    node *curr=head;
    if(head==NULL)
    return temp;
    if(head->data>x)
    {
        temp->next=head;
        return temp;
    }
    while(curr->next!=NULL && curr->next->data<x)
    {
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
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
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    head=sortedInsert(head,45);
    printList(head);
    return 0;
}