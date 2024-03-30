/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*>ST;
    void Traverse(TreeNode *root)
    {
        if(!root)
            return;
        TreeNode *tmp = root;
        while(tmp)
        {
            ST.push(tmp);
            tmp = tmp->left;
        }
    }
    BSTIterator(TreeNode* root) {
       Traverse(root);
    }
    
    int next() {
        TreeNode *t = ST.top();
        ST.pop();
        TreeNode *tmp = t->right;
        while(tmp)
        {
            ST.push(tmp);
            tmp = tmp->left;
        }
        return t->val;
    }
    
    bool hasNext() {
        return !ST.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */