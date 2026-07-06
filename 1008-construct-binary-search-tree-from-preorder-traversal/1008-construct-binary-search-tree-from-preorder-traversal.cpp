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
    int i=0;
    TreeNode* buildTree(vector<int>&pre,int ub){
        if(i==pre.size()||pre[i]>=ub)return nullptr;
        TreeNode* root=new TreeNode(pre[i++]);
        root->left=buildTree(pre,root->val);
        root->right=buildTree(pre,ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return buildTree(pre,INT_MAX);
    }

};