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
    ListNode* getMid(ListNode* head)
    {
        if(!head) return head;

        ListNode *slow = head, *fast = head;
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        if(!head or !head->next) return head;

        // ListNode* tmp = head , *prev = NULL;//->next;

        // while(tmp)
        // {
        //     ListNode *nxt = tmp->next;
        //     tmp->next = prev;
        //     prev = tmp;
        //     tmp = nxt;
        // }
        // return prev;

        ListNode *nxt = head->next;
        
        head->next = NULL;

        ListNode *new_head = reverse(nxt);

        nxt->next = head;

        return new_head;


        
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;

        ListNode* mid = getMid(head);

        ListNode* second = reverse(mid);

        mid = head;

        ListNode* tmp = second;
        while(tmp)
        {
            cout<<tmp->val<<" - ";
            tmp = tmp->next;
        }
        

        while(mid && second)
        {
            if(mid->val != second->val)
                return false;
            
            mid = mid->next;
            second = second->next;
        }
        return true;
        
    }
};