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

node *insertBegin(node *head,int x)
{
    node *temp=new node(x);
    temp->next=head;
    return temp; //here, we not changing head, as it will not be reflected in main's head
    // returning temp because we want to make temp as our new head
}

// node*insertBegin(node *head,int key)
// {
//     node *temp=new node(key);
//     if(head==nullptr)
//     return temp;
//     temp->next=head;
//     head=temp;
//     return temp;
// }

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
    node *head=NULL;
    head=insertBegin(head,30);
    head=insertBegin(head,20);
    head=insertBegin(head,10);
    printList(head);
    return 0;
}