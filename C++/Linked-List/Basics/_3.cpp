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

void printList(node *head)
{
    // here, no temporary variable current is declared, we are using head pointer to traverse the list
    // but the main's head is not modified
    while(head!=NULL)
    {
        cout<<head->data<<endl;;
        head=head->next;
    }
}

// 10 will be printed twice becuse in c++, like auto variables, copies of pointers are created when
// passsing in anpother funcion, but both the copy and original pointer variable have the same address pointing
int main()
{
    node *head= new node(10);
    printList(head);
    printList(head);
    return 0;
}