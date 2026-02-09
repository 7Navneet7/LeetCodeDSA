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
    void inorder(TreeNode* root,vector<int>&vals){
        if(!root)return;
        inorder(root->left,vals);
        vals.push_back(root->val);
        inorder(root->right,vals);
    }
    TreeNode* build(vector<int>&vals,int l,int h){
        if(l>h)return nullptr;
        int m=(l+h)/2;
        TreeNode* node=new TreeNode(vals[m]);
        node->left=build(vals,l,m-1);
        node->right=build(vals,m+1,h);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vals;
        inorder(root,vals);
        return build(vals,0,(int)vals.size()-1);
        
    }
};