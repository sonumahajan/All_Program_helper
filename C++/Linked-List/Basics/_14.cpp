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

void nodeFromLast(node* head,int posi)
{
    int len=1;
    node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        len++;
    }
    if(posi>len)
    return;
    curr=head;
    int count=1;
    while(count<(len-posi+1))
    {
        curr=curr->next;
        count++;
    }
    cout<<curr->data<<endl;
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
    nodeFromLast(head,2);
    return 0;
}
