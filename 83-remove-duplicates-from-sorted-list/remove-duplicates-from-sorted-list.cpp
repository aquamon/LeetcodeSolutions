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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode *dummy = new ListNode(-1);

        dummy->next = head;

        ListNode *curr = head , *prev = dummy;

        while(curr )
        {
            if(prev == dummy)
            {
                prev = curr;
                curr = curr->next;
                continue;
            }
            while(curr and curr->val == prev->val)
            {
                curr = curr->next;
            }
            if(!curr)
            {
                prev->next = NULL;
                break;
            }
            prev->next = curr;
            prev = curr;
            curr = curr->next;
            
            
        }

        return dummy->next;
    }
};