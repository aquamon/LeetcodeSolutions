/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return head;
        

        Node *temp = head;

        while(temp)
        {
            Node* newNode = new Node(temp->val);
            Node* nxt  = temp->next;
            temp->next = newNode;
            newNode->next = nxt;
            temp = nxt;
        }

        
        Node* curr = head;

        while(curr)
        {
            if(curr->random == NULL)
            {
                curr->next->random = NULL;
            }
            else
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;

        Node* curr2 = curr->next;

        Node *new_head = curr2;

        while(curr2->next != NULL)
        {
            curr->next = curr->next->next;
            curr2->next = curr2->next->next;
            curr2 = curr2->next;
            curr = curr->next;
        }

        curr->next = curr->next->next;
        return new_head;

       
    }
};