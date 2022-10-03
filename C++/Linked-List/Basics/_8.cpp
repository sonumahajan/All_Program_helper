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

node *deleteHead(node *head)
{
    if(head==NULL)
    return NULL;
    // head->next=head;
    // return head;
    // the above code is wrong as we are not deallocating the dynamically allocated memory
    else
    {
        node *temp=head->next;
        delete head;
        return temp;
    }
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
    head=deleteHead(head);
    printList(head);
    return 0;
}