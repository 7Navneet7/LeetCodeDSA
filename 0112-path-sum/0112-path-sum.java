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
    void dfs(TreeNode node,int curr,List<Integer>ans){
        if(node==null)return;
        curr=curr+node.val;
        if(node.left==null && node.right==null){
            ans.add(curr);
        }
        else{
            dfs(node.left,curr,ans);dfs(node.right,curr,ans);
        }
        curr-=node.val;

    }
    public boolean hasPathSum(TreeNode root, int tarSum) {
        List<Integer>ans=new ArrayList<>();
         dfs(root,0,ans);
         for(int it:ans){
            if(it==tarSum)return true;
         }
         return false;

        
    }
}