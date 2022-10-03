#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int key)
    {
        data=key;
        next=NULL;
    }
};

void deleteNode(node *givenNode)
{
    givenNode->data=givenNode->next->data;
    node *temp=givenNode->next;
    givenNode->next=temp->next;
    delete temp;
}

node *insertLast(node *head,int key)
{
    node *temp=new node(key);
    if(head==nullptr)
    return temp;
    node*curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

void printLL(node *head)
{
    if(head==NULL)
    return;
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    node *head=new node(10);
    head=insertLast(head,20);
    head=insertLast(head,30);
    head=insertLast(head,40);
    head=insertLast(head,50);
    head=insertLast(head,60);
    node *givenNode=head->next->next->next;
    deleteNode(givenNode);
    printLL(head);
    return 0;
}