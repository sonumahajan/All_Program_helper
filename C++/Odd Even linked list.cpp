/*  Given the head of a singly linked list, group all the nodes with odd indices together 
    followed by the nodes with even indices, and return the reordered list. 
    Example: 
      Input: head = [1,2,3,4,5]
      Output: [1,3,5,2,4] 
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) 
            return head;
        ListNode *odd=head, *evenhead=head->next, *even = evenhead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead;
        return head;
    }
};

// O(1) extra space complexity and O(n) time complexity.
