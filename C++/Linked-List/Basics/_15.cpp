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

void efficfromLast(node *head,int posi)
{
    node *first=head;
    node *second=head;
    int count=0;
    // int count =1;
    while(count!=posi)
    {
        if(first==NULL)
        return;
        first=first->next;
        count++;
    }
    while(first!=NULL)
    // while(first->next!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    cout<<second->data<<endl;
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
    efficfromLast(head,4);
    return 0;
}