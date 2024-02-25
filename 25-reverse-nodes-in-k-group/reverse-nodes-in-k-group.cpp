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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       
        int count = 0;

        ListNode* tmp = head;
        while(count < k and tmp)
        {
            tmp = tmp->next;
            count++;
        }

        if(count < k)
            return head;
        count = 0;    
        ListNode* prev = NULL , *curr = head;
        while(count < k)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        head->next = reverseKGroup(curr,k);

        return prev;


    }
};