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

node *insertAtPosi(node *head,int posi,int data)
{
    node *curr=head;
    node *temp=new node(data);
    if(posi==1) //to handle insearting at position 1
    {
        temp->next=head;
        return temp;
    }
    int trav=1;
    while(trav!=posi-1)
    {
        curr=curr->next;
        trav++;
    }
    if(curr==NULL) //to handle the case when postion is beyond range
    {
        return head;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
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
    head->next=new node(30);
    head->next->next=new node(50);
    head->next->next->next=new node(70);
    head=insertAtPosi(head,4,20);
    head=insertAtPosi(head,1,0);
    printList(head);
    return 0;
}