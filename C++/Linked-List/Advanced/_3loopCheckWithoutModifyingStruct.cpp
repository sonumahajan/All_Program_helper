#include <iostream>
using namespace std;

// break the next connection and point it to the temp node
// if a node already pointing temp, then there must be loop
// but, this breaks the linked list completely
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

bool loopCheck(node *head)
{
    if(head==NULL)
    return false;
    if(head->next==NULL)
    return false;
    node *temp=new node(0);
    node *curr=head;
    while(curr!=NULL)
    {
        if(curr->next==NULL)
        return false;
        if(curr->next==temp)
        return true;
        node *temp_next=curr->next;
        curr->next=temp;
        curr=temp_next;
    }
    return false;
}

int main()
{
    node *head=new node(10);
    head->next=new node(15);
    head->next->next=new node(20);
    head->next->next->next=new node(25);
    head->next->next->next->next=head->next;
    cout<<loopCheck(head);
    return 0;
}