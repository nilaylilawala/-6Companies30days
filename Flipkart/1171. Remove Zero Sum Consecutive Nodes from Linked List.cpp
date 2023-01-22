class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m;
        int sum=0;
        ListNode* dummy = new ListNode(), *p = dummy;
        dummy->next = head;
        while(p) {
            sum+=p->val;
            if(m.count(sum)) {
                
                ListNode* curr = m[sum]->next;
                int x = sum+curr->val;
                while(x!=sum) {
                    m.erase(x);
                    curr = curr->next;
                    x+=curr->val;
                }
                m[sum]->next = p->next;
            }
            else {
                m[sum] = p;
            }
            p = p->next;
        }
        return dummy->next;
    }
};
