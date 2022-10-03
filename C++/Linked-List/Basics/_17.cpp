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

node *recurReverse(node *head)
{
    if(head==NULL||head->next==NULL)   
    return head;
    node *restHead=recurReverse(head->next);
    node *restTail=head->next;
    restTail->next=head;
    head->next=NULL;
    return restHead;
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
    head=recurReverse(head);
    printList(head);
    cout<<endl; 
    return 0;
}