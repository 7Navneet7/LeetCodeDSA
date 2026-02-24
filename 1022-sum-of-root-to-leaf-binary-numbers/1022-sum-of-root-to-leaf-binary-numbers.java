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
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root,0);
        
    }
    int dfs(TreeNode root, int curr){
        if(root==null)return 0;
        curr=(curr<<1)|root.val;
        if(root.right==null && root.left==null)return curr;
        return dfs(root.left,curr)+dfs(root.right,curr);
    }
}