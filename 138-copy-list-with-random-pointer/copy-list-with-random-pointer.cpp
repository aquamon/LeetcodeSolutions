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
        return NULL;
     Node*tmp = head;

     while(tmp)
     {
         Node* dup = new Node(tmp->val);
         Node* tmp2 = tmp;
         tmp = tmp->next;
         tmp2->next = dup;
         dup->next = tmp;   
         
     }

     tmp = head;

     while(tmp)
     {
         if(tmp->random == NULL)
            tmp->next->random = NULL;
        else
            tmp->next->random = tmp->random->next;
        
        tmp = tmp->next->next;
     }

     Node* newhead = head->next;

     tmp = head;
     Node* tmp2 = newhead;

     while(tmp2->next)
     {
        tmp->next = tmp->next->next;
        tmp2->next = tmp2->next->next;
        tmp2 = tmp2->next;
        tmp = tmp->next;
     }
     tmp->next = tmp->next->next;

    return newhead;


    }
};