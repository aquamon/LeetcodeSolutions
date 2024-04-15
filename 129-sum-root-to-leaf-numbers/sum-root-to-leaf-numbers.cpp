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
    
    int solve(TreeNode* root,int curr_num)
    {
        if(!root)
            return 0;
        
        if(!root->left  and !root->right)
        {
            curr_num *= 10;
            curr_num += root->val;
            return curr_num;
        }

        curr_num *=10;
        curr_num += root->val;

        int left = solve(root->left,curr_num);
        int right = solve(root->right,curr_num);
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        
        
        int curr_num = 0;

        return solve(root,curr_num);
        
    }
};