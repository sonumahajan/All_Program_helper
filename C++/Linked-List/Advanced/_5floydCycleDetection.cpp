#include <iostream>
using namespace std;

// approach: use two pointers, one is slow pointer, moving one node at a time
// 2nd is fast pointer moving 2 nodes at a time
// if there is a cycle, then they will surely meet
// maths: distance will be increasing by 1 node always
// when the distance becomes the length of the loop, they will meet
// 2x speed to ensure the distance after 1 steps increment will lead to n, not n-1 or n+1
// n is loop length

struct node
{
    node *next;
    int data;
    node(int key)
    {
        data=key;
        next=NULL;
    }
};

bool loopCheck(node *head)
{
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
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