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
        
        if(!head or !head->next)
            return head;
        
        ListNode *temp = new ListNode(0);

        temp->next = head;

        ListNode *curr = head , *prev = temp;

        while(curr and curr->next)
        {
            if(curr->next and curr->val == curr->next->val)
            {
                while(curr->next and curr->val == curr->next->val)
                {
                    curr = curr->next;
                }
                prev->next = curr->next;
            }
            else
            {
                prev = prev->next;
            }

            curr = curr->next;

        }
        return temp->next;
    }
};