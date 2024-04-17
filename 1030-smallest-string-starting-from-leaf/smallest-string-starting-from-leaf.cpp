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
    pair<string,string> solve(TreeNode *root)
    {
        if(!root)
            return {"zzzzzz","zzzzzz"};
        if(!root->left and !root->right)
        {
            char x = root->val + 'a';
            string res = "";
            res += x;
            return  {res,res};
        }

        pair<string,string> Left = solve(root->left);
        pair<string,string> Right = solve(root->right);

       Left.first += root->val + 'a';
       Left.second += root->val + 'a';

       Right.first += root->val + 'a';
       Right.second += root->val + 'a';

       string L = Left.first < Left.second ? Left.first : Left.second;
       string R = Right.first < Right.second ? Right.first : Right.second;

       return {L,R}; 
       
    }
    string smallestFromLeaf(TreeNode* root) {
        
       
        pair<string,string> res =  solve(root);

        if(res.first < res.second)
            return res.first;
        return res.second;

    }
};