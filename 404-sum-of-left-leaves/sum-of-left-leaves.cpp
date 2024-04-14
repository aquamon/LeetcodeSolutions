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
    int solve(TreeNode *root, bool isLeft)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right and isLeft)
        {
            return root->val;
        }

        isLeft = true;
        int x = solve(root->left,isLeft);
        isLeft = false;
        int y = solve(root->right,isLeft);
        return x+y;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        bool isLeft = false;

        return solve(root,isLeft);

    }
};