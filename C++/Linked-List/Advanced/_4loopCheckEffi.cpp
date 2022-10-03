#include <iostream>
#include <unordered_set>
using namespace std;

// store the nodes address in the set
// if for a node, address is alreadry present, then there is a loop

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
    unordered_set<node *>visited;
    node *curr=head;
    while(curr->next!=NULL)
    {
        if(visited.find(curr)!=visited.end())
        return true;
        visited.insert(curr);
        curr=curr->next;
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