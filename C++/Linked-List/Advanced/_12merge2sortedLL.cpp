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

node *mergedLL(node *h1,node *h2)
{
    node *c1=h1;
    node *c2=h2;
    node *head=NULL;
    node *tail=NULL;
    if(h1==NULL)
    return h2;
    if(h2==NULL)
    return h1;
    // handling the corner case of making the new head
    // initiaally the head will be tail 
    if(c1->data<=c2->data)
    {
        head=c1;
        tail=c1;
        c1=c1->next;
    }
    else
    {
        head=c2;
        tail=c2;
        c2=c2->next;
    }
    // now, whichever is smaller, we assign the tail next as that node and make that the new tail 
    // and move that current node
    while(c1!=NULL && c2!=NULL)
    {
        if(c1->data<=c2->data)
        {
            tail->next=c1;
            tail=tail->next;
            c1=c1->next;
        }
        else
        {
            tail->next=c2;
            tail=tail->next;
            c2=c2->next;
        }
    }
    // filling any left ele 
    if(c1==NULL)
    tail->next=c2;
    else
    tail->next=c1;
    return head;
}

int main()
{
    node *h1=new node(10);
    h1->next=new node(20);
    h1->next->next=new node(30);
    h1->next->next->next=new node(40);
    node *h2=new node(5);
    h2->next=new node(15);
    h2->next->next=new node(17);
    h2->next->next->next=new node(18);
    h2->next->next->next->next=new node(35);
    node *head=mergedLL(h1,h2);
    node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    return 0;
}