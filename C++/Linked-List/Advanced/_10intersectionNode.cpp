#include <iostream>
#include <unordered_set>
using namespace std;

// prob: given two linked list intersecting at some point
// we have to find the intersection point
// O(m+n) time, O(m) space

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

int intersection(node *h1,node *h2)
{
    unordered_set<node *>visited;
    node *curr=h1;
    while(curr!=NULL)
    {
        visited.insert(curr);
        curr=curr->next;
    }
    curr=h2;
    while(curr!=NULL)
    {
        if(visited.find(curr)!=visited.end())
        return curr->data;
        curr=curr->next;
    }
    return INT_MIN;
}

int main()
{
    node *h1=new node(5);
    h1->next=new node(8);
    h1->next->next=new node(7);
    h1->next->next->next=new node(10);
    h1->next->next->next->next=new node(12);
    h1->next->next->next->next->next=new node(15);
    node *h2=new node(9);
    h2->next=h1->next->next->next;
    cout<<"the intersection node is "<<intersection(h1,h2)<<endl;
    return 0;
}