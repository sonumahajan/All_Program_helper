#include <iostream>
using namespace std;

// idea is to maintain a visited member in structure for each node
// initially all are unvisited
// similar to loop check in graphs

struct node
{
    node*next;
    int data;
    bool visited;
    node(int key)
    {
        data=key;
        next=nullptr;
        visited=false;
    }
};

bool loopCheck(node *head)
{
    if(head==NULL)
    return false;
    if(head->next==NULL)
    return false;
    node*curr=head;
    while(curr!=NULL)
    {
        if(curr->visited==0)
        {
            curr->visited=true;
            curr=curr->next;
        }
        else
        return true;
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