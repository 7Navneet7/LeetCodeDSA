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
    bool isval(TreeNode* root,long long min,long long max){
        if(root==nullptr)return 1;
        if(root->val<=min||root->val>=max)return 0;
        return (isval(root->left,min,root->val)&&(isval(root->right,root->val,max)));
    }
    bool isValidBST(TreeNode* root) {
        return isval(root,LLONG_MIN,LLONG_MAX);
    }
};