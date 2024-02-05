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
        
        ListNode *prev = NULL , *curr = head , *curr2 = head->next;

        while(curr->next)
        {
            if(curr->val != curr2->val)
            {
                prev = curr;
                curr = curr2;
                if(curr2)
                    curr2 = curr2->next;
            }
            else
            {
                while(curr)
                {
                    curr2 = curr2->next;
                    if(curr2 == NULL)
                    {
                       if(prev)
                            prev->next = NULL;
                        else
                            return NULL;
                        
                        return head;

                    }
                    if(curr->val != curr2->val)
                    {
                        curr = curr2;
                        curr2 = curr2->next;
                        if(prev)
                            prev->next = curr;
                        else
                            head = curr;
                        break;
                    }
                }
            }
        }
        return head;
        
    }
};