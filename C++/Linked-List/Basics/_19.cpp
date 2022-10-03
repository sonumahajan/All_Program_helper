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

node *insertEnd(node *head,int x)
{
    node *temp=new node(x);
    if(head==NULL)
    return temp;
    node *curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}

void removeDupli(node *head)
{
    node *curr=head;
    while(curr!=NULL&&curr->next!=NULL) //curr is checked for null only to confirm we 
                                        //are not traversing an empty node
    {
        if(curr->data==curr->next->data)
        {
            node *temp=curr->next; //to prevent memory leak
            curr->next=curr->next->next;
            delete temp; //to prevent memory leak
        }
        else curr=curr->next;
    }
    // return head;
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
    head=insertEnd(head,20);
    head=insertEnd(head,20);
    head=insertEnd(head,30);
    head=insertEnd(head,30);
    head=insertEnd(head,30);
    printList(head);
    cout<<endl;
    removeDupli(head);
    printList(head);
    cout<<endl; 
    return 0;
}