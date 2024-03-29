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
    public boolean check(int C,TreeNode root,int T)
    {
        if(root == null)
            return false;
        C += root.val;

        if(C == T && root.left == null && root.right == null)
            return true;
        
        return check(C,root.left,T) || check(C,root.right,T);
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        
        if(root == null)
            return false;
        
        int curr_sum = 0;

        return check(curr_sum,root,targetSum);
    }
}