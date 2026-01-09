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
    TreeNode* ans=nullptr;
    int maxDepth=-1;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        helper(root,0);
        return ans;
    }
    int helper(TreeNode* root,int level){
        if(root==nullptr)return 0;
        int left=helper(root->left,level+1);
        int right=helper(root->right,level+1);
        if(left==right && level+left>=maxDepth){
            maxDepth=level+left;
            ans=root;
            cout<<(root->val);
        }
        return 1+max(left,right);
    }
};