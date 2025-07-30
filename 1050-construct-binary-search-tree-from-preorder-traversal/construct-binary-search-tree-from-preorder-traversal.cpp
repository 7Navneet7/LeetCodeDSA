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
    int idx=0;
    TreeNode* helper(vector<int>&preorder,int min,int max) {
        if (idx>=preorder.size())return NULL;
        int val=preorder[idx];
        if(val<=min||val>=max)return NULL;
        idx++;
        TreeNode* root=new TreeNode(val);
        root->left=helper(preorder,min,root->val);
        root->right=helper(preorder,root->val,max);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       return helper(preorder,INT_MIN,INT_MAX);
    }    
};