
class Cmp {
    public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> minh;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                minh.push(lists[i]);
            }
        }
        
        while(!minh.empty()) {
            ListNode* topNode = minh.top();
            minh.pop();
            
            if(topNode->next) minh.push(topNode->next);
            
            temp->next = topNode;
            temp = topNode;
            
        }
        
        return dummy->next;
    }
};
