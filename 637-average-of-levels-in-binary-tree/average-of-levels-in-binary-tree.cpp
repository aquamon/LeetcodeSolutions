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
    
    vector<double> averageOfLevels(TreeNode* root) {
        
        

        queue<TreeNode*>Q;
        vector<double> ans;
        Q.push(root);

        while(!Q.empty())
        {
            int sz = Q.size();

            long double  sum = 0;
           for(int i=0;i<sz;i++)
            {
                TreeNode *curr = Q.front();
                Q.pop();
                if(curr->left)
                    Q.push(curr->left);
                if(curr->right)
                    Q.push(curr->right);
                
                sum += curr->val;
            }

            ans.push_back(sum/sz);
        }

        return ans;
    }
};