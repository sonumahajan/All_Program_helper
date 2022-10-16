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

node *recRevLL(node *curr,node *prev)
{
    if(curr==NULL)
    return prev;
    node *next=curr->next;
    curr->next=prev;
    return recRevLL(next,curr);
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
    head=recRevLL(head,NULL);
    printList(head);
    cout<<endl; 
    return 0;
}