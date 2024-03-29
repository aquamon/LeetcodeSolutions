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
    bool check(TreeNode *root,int curr_sum ,int targetSum)
    {
        if(!root)
            return false;
        curr_sum += root->val;
        if(curr_sum == targetSum and !root->left and !root->right)
            return true;
       
        
        

        return check(root->left,curr_sum,targetSum) or check(root->right,curr_sum,targetSum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        int curr_sum = 0;

        return check(root,curr_sum,targetSum);
    }
};