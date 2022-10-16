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

void recPrint(node *head)
{
    if(head==NULL)
    return;
    cout<<head->data<<"->";
    recPrint(head->next);
}

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    recPrint(head);
    return 0;
}