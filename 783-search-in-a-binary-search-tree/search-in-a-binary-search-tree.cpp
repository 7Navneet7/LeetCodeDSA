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
    vector<int>preOrder(TreeNode* root){
        vector<int>pre;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            pre.push_back(root->val);
            if(root->right!=nullptr)st.push(root->right);
            if(root->left!=nullptr)st.push(root->left);
        }
        return pre;
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=nullptr && root->val!=val){
            root=(root->val>val?root->left:root->right);
        }
        return root;
    }
};