#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void LinkTraversal(struct node* head){
    while(head->next!=NULL){
        printf("Element is : %d\n",head->data);
        head=head->next;
    }
    printf("Element is : %d\n",head->data);
}

struct node* InsertInStart(struct node* head, int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=head;
    return ptr;

}

struct node* InsertAtEnd(struct node* head, int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;

    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* InsertInBw(struct node* head, int index, int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;

    struct node* temp=head;

    int i=0; 
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    ptr->next=temp->next;
    temp->next=ptr;

    return head;
}

struct node* InsertAfterNode(struct node* head, struct node* n1, int val){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;

    ptr->next=n1->next;
    n1->next=ptr;

    return head;
}


int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=2;

    struct node* second=(struct node*)malloc(sizeof(struct node));
    second->data=3;

    struct node* third=(struct node*)malloc(sizeof(struct node));
    third->data=4;

    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    fourth->data=5;

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    //head=InsertInStart(head, 1);
    //head=InsertAtEnd(head, 6);
    //head=InsertInBw(head, 2, 10);
    head=InsertAfterNode(head, third, 56);
    LinkTraversal(head);
    return 0;
}