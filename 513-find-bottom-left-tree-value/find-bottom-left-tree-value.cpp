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
    void solve(int &maxLvl,int lvl,int &ans, TreeNode* root)
    {
        if(!root)
            return;
        
         if(lvl > maxLvl)
        {
            ans = root->val;
            // cout<<ans<<" : ";
            maxLvl = lvl;
        }

        solve(maxLvl,lvl+1,ans,root->left);
        
        solve(maxLvl,lvl+1,ans,root->right);
    }
    int findBottomLeftValue(TreeNode* root) {
        

        if(!root)
            return -1;
        
        int ans = root->val;
        int lvl = 0 , maxLvl = 0;

        solve(maxLvl,lvl,ans,root);

        return ans;

    }
};