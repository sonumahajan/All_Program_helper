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

int searchLL(node *head,int &x)
{
    node *current=head;
    int posi=1;
    while(current!=NULL)
    {
        if(current->data==x)
        return posi;
        posi++;
        current=current->next;
    }
    return -1;
}


int recSearch(node *head,int x)
{
    if(head==NULL)
    return -1;
    if(head->data==x)
    return 1;
    int res=recSearch(head->next,x);
    if(res==-1)
    return -1;
    else
    return res+1;
}

int main()
{
    node *head=new node(10);
    head->next=new node(20);
    head->next->next=new node(30);
    head->next->next->next=new node(40);
    int x=50;
    cout<<searchLL(head,x)<<endl;
    cout<<recSearch(head,x)<<endl;
    return 0;
}