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
    pair<int,int> solve(TreeNode *root)
    {
        if(!root)
            return {INT_MIN,0};
        
               
        pair<int,int> LST = solve(root->left);
        pair<int,int> RST = solve(root->right);

        int path_sum_max = max({(root->val + max(LST.second,0) + max(RST.second,0)) , LST.first , RST.first});

        int curr_max = root->val + max({0,LST.second, RST.second}); 

        return {path_sum_max , curr_max};
    }
    int maxPathSum(TreeNode* root) {
        
        return solve(root).first;
    }
};