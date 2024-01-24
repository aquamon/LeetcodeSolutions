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
    int ans = 0;

    // bool check(vector<int>&path)
    // {
    //     int freq[10] = {0};
    //     for(int i=0;i<path.size();i++)
    //     {
    //         freq[path[i]]++;
    //     }
    //     int odd = 0, even = 0;

    //     for(int x:freq)
    //     {
    //         if(x % 2 == 0)
    //             even++;
    //         else
    //             odd++;
    //     }

    //     if(odd > 1)
    //         return false;
    //     if(even == 0)
    //         return false;
    //     return true;
    // }
    void solve(TreeNode* root, int path)
    {
        if(!root)
            return;
        path = path ^ (1<<root->val);
        if(!root->left and !root->right)
        {
            // for(int x:path)
            // {
            //     cout<<x<<"--";
            // }
            // cout<<endl;
            // if(check(path))
            //     ans++;
            if((path & (path-1)) == 0){
                ++ans;
            }
            
        }
        else
        {
            
            solve(root->left,path);
        
       
            solve(root->right,path);
        }

        
       
            
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        // vector<int>path; //= {2,1,1};
        int path = 0;
        solve(root,path);
        // cout<<check(path)<<"sss";
        return ans;
    }
};