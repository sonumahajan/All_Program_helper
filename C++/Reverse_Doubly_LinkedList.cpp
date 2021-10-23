Node* reverseDLL(Node * head)
{
struct Node* next;
struct Node* current = head;
struct Node* prev = NULL;

while(current!=NULL){
    next = current->next;
    current->next = prev;
    current->prev = next;
    prev = current;
    current = next;
}
return prev;
}
