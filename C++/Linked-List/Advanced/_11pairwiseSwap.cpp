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

void pairwiseSwap(node *head)
{
    node *curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
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
    node *head=new node(5);
    head->next=new node(8);
    head->next->next=new node(7);
    head->next->next->next=new node(10);
    head->next->next->next->next=new node(12);
    head->next->next->next->next->next=new node(15);
    pairwiseSwap(head);
    printLL(head);
    return 0;
}