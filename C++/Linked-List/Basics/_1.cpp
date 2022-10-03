#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int key)
    {
        data=key;
        next=nullptr;
    }
};

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    return 0;
}