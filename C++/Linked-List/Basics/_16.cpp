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

// node *reverseList(node* head)
// {
//     node *prev=NULL;
//     node *curr=head;
//     while(curr!=NULL)
//     {
//         node *next=curr->next; //to store curr next so that we dont lose track of upcoming nodes
//         curr->next=prev;
//         prev=curr;
//         curr=next;
//     }
//     return prev;
// }

node *reverseList(node *head)
{
    node*prev=nullptr;
    node*curr=head;
    while(curr!=nullptr)
    {
        node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
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
    head=reverseList(head);
    printList(head);
    cout<<endl; 
    return 0;
}