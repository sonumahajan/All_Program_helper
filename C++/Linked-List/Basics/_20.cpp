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

void deleteGivenNode(node *givenNode)
{
    // copying the data of next node to given node
    givenNode->data=givenNode->next->data;
    // deleting the next node after given node, since it can be done in O(1) time
    node *temp=givenNode->next;
    givenNode->next=givenNode->next->next;
    delete temp;
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
    node *givenNode=head->next->next;
    givenNode->next=new node(40);
    printList(head);
    cout<<endl;
    deleteGivenNode(givenNode);
    printList(head);
    cout<<endl;
    return 0;
}