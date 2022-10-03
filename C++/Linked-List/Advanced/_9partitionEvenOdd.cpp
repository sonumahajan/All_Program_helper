#include <iostream>
using namespace std;

// maintain 4 nodes, evenStart, evenEnd, oddStart, oddEnd
// fill them till curr is not nullptr
// at last join even's tail and odd's head, and make the tail of odd as nullptr
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

node *evenOdd(node *head)
{
    node *evenS=NULL;
    node *evenE=NULL;
    node *oddS=NULL;
    node *oddE=NULL;
    node *curr=head;
    for(curr=head;curr!=NULL;curr=curr->next)
    {
        int x=curr->data;
        if(x%2==0)
        {
            // to handle 1st even
            if(evenS==NULL)
            {
                evenS=curr;
                evenE=curr;
            }
            else
            {
                evenE->next=curr;
                evenE=curr;
            }
        }
        else
        {
            // to handle 1st odd
            if(oddS==NULL)
            {
                oddS=curr;
                oddE=curr;
            }
            else
            {
                oddE->next=curr;
                oddE=curr;
            }
        }
    }
    if(evenS==NULL || oddS==NULL)
    return head;
    else
    {
        evenE->next=oddS;
        oddE->next=NULL;
        return evenS;
    }
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
    head=insertLast(head,13);
    head=insertLast(head,14);
    head=insertLast(head,3);
    head=insertLast(head,6);
    head=insertLast(head,8);
    head=insertLast(head,9);
    head=evenOdd(head);
    printLL(head);
    return 0;
}