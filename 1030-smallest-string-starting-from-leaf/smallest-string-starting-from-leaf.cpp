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
class Solution {
public:

    string smallest = "";
    void dfs(TreeNode* root, string currentString)
    {
        if(!root)
            return;
        
        currentString = char(root->val + 'a') + currentString;

        if(!root->left and !root->right)
        {
            if(smallest == "" or currentString < smallest)
            {
                smallest = currentString;
            }
        }

        dfs(root->left,currentString);
        dfs(root->right,currentString);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        dfs(root,"");

        return smallest;
    }
};