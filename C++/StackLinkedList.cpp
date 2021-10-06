#include<iostream>
using namespace std;

struct Node{                            // From beginning O(1) for Insertion /deletion
    int data;                           // From end O(n) for Insertion /deletion
    Node *next;
};

Node *top = NULL;
void Push(int data){
    Node *temp = new Node();
    temp -> data = data;
    temp -> next = top;
    top = temp; 
}

void Pop(){
    if(top == NULL){
        cout << "Stack is Empty" << endl;
    }
    Node *temp1 = top;
    top = temp1 -> next;
    free(temp1);
}

void Print(){
    Node *temp = top;
    while(temp != NULL){
        cout << temp -> data << endl;
        temp = temp -> next;
    }
   printf("\n"); 
}
int Top(){
    return top->data;
}

int main(){
    Push(6);
    Push(7);
    Push(5);
    Push(4);
    Print();
    Pop();
    Pop();
    Print();

    Top();
}











