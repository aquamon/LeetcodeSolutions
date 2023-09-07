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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode*  prev = NULL , *curr = head;

        while(left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }

        ListNode* con = prev , *tail = curr;

        while(right > 0)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            right--;
        }
        if(con != NULL)
            con->next = prev;
        else
            head = prev;
        tail->next = curr;
        return head;



    }
};