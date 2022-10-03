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

node* reverseInGroups(node*head,int k)
{
    int i=0;
    if(head->next==NULL)
    return head;
    node*curr=head;
    node*prev=nullptr;
    node*next=nullptr;
    while(curr!=NULL && i<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        i++;
    }
    // reversing next grps
    if(next!=NULL)
    {
        node *recHead=reverseInGroups(next,k);
        // connecting last node of 1sr grp and 1st node of last grp
        head->next=recHead;
    }
    return prev;
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

void printList(node *head)
{
    node *curr=head;
    if(head==NULL)
    return;
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
    head=insertLast(head,70);
    head=insertLast(head,80);
    head=reverseInGroups(head,3);
    printList(head);
    cout<<endl;
    return 0;
}