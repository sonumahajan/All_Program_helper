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

void findMiddle(node *head)
{
    if(head==NULL)
    return;
    int count=1;
    node* curr=head;
    while(curr->next!=NULL)
    {
        curr=curr->next;
        count++;
    }
    int middle=(count/2)+1;
    int trav=1;
    curr=head;
    while(trav!=middle)
    {
        curr=curr->next;
        trav++;
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
    findMiddle(head);
    return 0;
}