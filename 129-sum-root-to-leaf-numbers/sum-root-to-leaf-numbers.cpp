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
    void rootToLeaf(TreeNode *root,int curr, int &ans)
    {
        if(!root)
            return;
        curr *= 10;
        curr += root->val;

        if(!root->left and !root->right)
        {
            ans += curr;
            return;
        }
        rootToLeaf(root->left,curr,ans);
        rootToLeaf(root->right,curr,ans);
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int curr = 0 ;
        // vector<int>nums;
        int ans = 0;
        rootToLeaf(root,0,ans);
        
        // for(int x : nums)
        // {
        //     ans += x;
        // }
        return ans;

    }
};