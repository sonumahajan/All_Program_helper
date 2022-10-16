#include <iostream>
using namespace std;

struct node
{
    node *next;
    int data;
    node(int key)
    {
        next=NULL;
        data=key;
    }
};

int loopSize(node *head)
{
    if(head->next==head)
    return 1;
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        break;
    }
    // if no loop, then return 0
    if(slow!=fast)
    return 0;
    int size=1;
    slow=slow->next;
    while(slow!=fast)
    {
        size++;
        slow=slow->next;
    }
    return size;
}

int main()
{
    node *head=new node(10);
    head->next=new node(15);
    head->next->next=new node(20);
    head->next->next->next=new node(25);
    head->next->next->next->next=head->next;
    cout<<"the size of loop is "<<loopSize(head)<<endl;
    return 0;
}
