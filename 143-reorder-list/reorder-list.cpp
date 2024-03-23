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
    ListNode* reverse(ListNode *head)
    {
        if(!head)
            return head;
        
        ListNode *prev = NULL , *curr = head;

        while(curr)
        {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        if(!head or !head->next)
            return;
        
        ListNode *slow = head, *fast = head;

        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // ListNode *tmp = slow;
        // tmp = tmp->next;

        // if(!tmp)
        //     return;
        ListNode* it = head;
        while(it->next != slow)
        {
            it = it->next;
        }
        
        it->next = reverse(slow);

        ListNode *p1 = head , *p2 = it->next;
        ListNode *P2 = p2;
        while(p1->next != P2)
        {
            ListNode* tmp = p1->next;
            p1->next = p2;
            ListNode* tmp2 = p2->next;
            p2->next = tmp;
            p1 = tmp;
            p2 = tmp2;
        }

        p1->next = p2;



    }
};