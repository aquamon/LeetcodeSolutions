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
    void rootToLeaf(TreeNode *root,int curr, vector<int>&nums)
    {
        if(!root)
            return;
        curr *= 10;
        curr += root->val;

        if(!root->left and !root->right)
        {
            nums.push_back(curr);
            return;
        }
        rootToLeaf(root->left,curr,nums);
        rootToLeaf(root->right,curr,nums);
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int curr = 0 ;
        vector<int>nums;

        rootToLeaf(root,0,nums);
        int ans = 0;
        for(int x : nums)
        {
            ans += x;
        }
        return ans;

    }
};