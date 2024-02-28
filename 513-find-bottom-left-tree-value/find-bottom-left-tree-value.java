/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public void solve(TreeNode root, int lvl, int[] maxLvl, int[] ans)
    {
        if(root == null)
            return;
        
        if(lvl > maxLvl[0])
        {
            ans[0] = root.val;
            maxLvl[0] = lvl;
        }

        solve(root.left,lvl+1,maxLvl,ans);
        solve(root.right,lvl+1,maxLvl,ans);
    }

    public int findBottomLeftValue(TreeNode root) {
        
        if(root == null)
            return -1;
        
        int lvl = 0;
        int [] max_lvl = {0};

        int [] ans = {root.val};

        solve(root,lvl,max_lvl,ans);

        return ans[0];
    }
}