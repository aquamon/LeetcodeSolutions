/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    Node* solve(Node *root)
    {
        queue<Node*>Q;

        Q.push(root);

        while(!Q.empty())
        {
            vector<Node*>temp;

            int size = Q.size();
            while(size--)
            {
                Node *curr = Q.front();
                Q.pop();
                temp.push_back(curr);
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
            }

            for(int i=0;i<temp.size()-1;i++)
            {
                temp[i]->next = temp[i+1];
            }
        }

        return root;
    }
    Node* connect(Node* root) {
        
        if(!root)
            return root;
        
        return solve(root);
    }
};