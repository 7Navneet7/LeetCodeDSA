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
    void dfs(TreeNode root,StringBuilder sb,List<String>ans){
        if(root==null)return;
        int len=sb.length();
        if(len>0)sb.append("->");
        sb.append(root.val);
        if(root.left==null && root.right==null){
            ans.add(sb.toString());
            //sb.deleteCharAt(sb.length() - 1);
            //return;
        }
        else{dfs(root.left,sb,ans);dfs(root.right,sb,ans);}
        sb.setLength(len);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String>ans=new ArrayList<>();
        StringBuilder sb=new StringBuilder();
        dfs(root,sb,ans);
        return ans;
        
    }
}