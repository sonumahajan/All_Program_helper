/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
   struct cmp {
        bool operator()(const ListNode* l, const ListNode* r) 
        {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto it : lists)
        {
            if(it)
            q.push(it);
        }
        ListNode* dummy=new ListNode;
        ListNode* temp=dummy;
        while(!q.empty())
        {
            ListNode* t=q.top();
            q.pop();
            ListNode* curr= new ListNode(t->val);
            temp->next=curr;
            temp=temp->next;
            if(t->next)
            q.push(t->next);
        }
        return dummy->next;
    }
};
