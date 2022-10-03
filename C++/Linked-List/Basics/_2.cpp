#include <iostream>
using namespace std;

struct node
{
    int data; //1st member of this struct is data
    node *next;//2nd member is next, storing address of next node
    // creating node
    node(int x)
    {
        data=x; 
        next=NULL;
    }
};

void printList(node *head)
{
    node *current=head;
    while(current!=NULL)
    {
    cout<<current->data<<"->";
    current=current->next; //current will now point to the next node, i.e., having address of next node
    }
    cout<<"NULL"<<endl;
}

// void printList(node *head)
// {
//     node *curr=head;
//     while(curr!=nullptr)
//     {
//         cout<<curr->data<<" ";
//         curr=curr->next;
//     }
// }

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    printList(head);
    return 0;
}