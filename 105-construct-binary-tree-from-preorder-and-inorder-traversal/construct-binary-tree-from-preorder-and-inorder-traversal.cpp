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
    TreeNode* build(vector<int>&P,int i1,int j1,vector<int>&I,int i2,int j2)
    {
        if(i1 > j1)
            return NULL;
        
        TreeNode *node = new TreeNode(P[i1]);

        int i;
        for(i=i2;i<=j2;i++)
        {
            if(P[i1] == I[i])
                break;
        }

        node->left = build(P,i1+1,i1+i-i2,I,i2,i-1);
        node->right = build(P,i1+i-i2+1,j1,I,i+1,j2);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};