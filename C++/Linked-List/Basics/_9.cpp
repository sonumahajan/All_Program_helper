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

node *deleteLast(node *head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
    delete head;
    return NULL;
    }
    node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
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
    printList(head);
    cout<<endl;
    head=deleteLast(head);
    printList(head);
    return 0;
}