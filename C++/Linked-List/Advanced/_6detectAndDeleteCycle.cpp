#include <iostream>
using namespace std;

// approach :
// use floyd cycle detection to find the meeting node
// when found, then move the slow pointer to head, and move both slow and fast one steps
// until their nexts is same node, which will be the end point of the loop
// make tat next of fast as nullptr

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

void deleteLoop(node *head)
{
    if(head->next==head)
    {
        head->next=NULL;
        return;
    }
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            // stop traversal at the meeting point
            break;
        }
    }
    if(slow!=fast)
    return;
    slow=head;
    // stop before the common node
    // and make the next of fast as null
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
}

bool loopCheck(node *head)
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
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
    head->next=new node(15);
    head->next->next=new node(20);
    head->next->next->next=new node(25);
    head->next->next->next->next=head->next;
    deleteLoop(head);
    printLL(head);
    cout<<loopCheck(head)<<endl;
    return 0;
}