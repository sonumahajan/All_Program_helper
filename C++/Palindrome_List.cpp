/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* find_middle(ListNode* head,int n)
        {
            ListNode *slow=head,*fast=head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
            } 
            if(n&1)
                return slow->next;
            else
                return slow;
        }

ListNode* reverse_link(ListNode* head)
        {
            ListNode *prev=NULL;
            ListNode *curr=head;
            ListNode *next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }

int Solution::lPalin(ListNode* A) {
    if(A==NULL || A->next==NULL){
        return 1;
    }
    ListNode* head=A;
    ListNode* tail=A;
    int n=0;
    while(tail!=NULL){
        tail=tail->next;
        n++;
    }
    tail=A;
    ListNode* list_mid=find_middle(tail,n);
    ListNode* rev_head=reverse_link(list_mid);
    while(rev_head!=NULL){
        if(head->val!=rev_head->val)
        return 0;
        head=head->next;
        rev_head=(rev_head->next);
    }
    return 1;
}