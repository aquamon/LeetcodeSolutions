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
    unordered_map<int,int>M;
    int idx;
    TreeNode* build(vector<int>&P,int s,int e)
    {
        if(s > e)
            return NULL;
        
        int rootvalue = P[idx++];
        TreeNode *node = new TreeNode(rootvalue);
        node->left = build(P,s,M[rootvalue]-1);
        node->right = build(P,M[rootvalue]+1,e);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        idx=0;

        for(int i=0;i<inorder.size();i++)
            M[inorder[i]] = i;

        return build(preorder,0,preorder.size()-1);
        
    }
};
