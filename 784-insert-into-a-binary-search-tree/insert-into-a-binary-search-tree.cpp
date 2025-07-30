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
    TreeNode* Ceil(TreeNode* root,int val){
        TreeNode* node=nullptr;
        while(root!=nullptr){
            if(root->val==val)return root;
            if(root->val>val){
                node=root;
                root=root->left;
            }
            else root=root->right;
        }
        return node;
    }
    TreeNode* Floor(TreeNode* root,int val){
        TreeNode* node=nullptr;
        while(root!=nullptr){
            if(root->val==val)return root;
            if(root->val<val){
                node=root;root=root->right;
            }
            else root=root->left;
        }
        return node;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        TreeNode* ceil=Ceil(root,val);
        TreeNode* floor=Floor(root,val);
        if(ceil!=nullptr && ceil->left==nullptr)ceil->left=node;
        //else if(ceil->right==nullptr)ceil->right=node;
        //else if(floor->left==nullptr)floor->left=node;
        else if(floor!=nullptr && floor->right==nullptr) floor->right=node;
        else return node;
        return root;
    }
};