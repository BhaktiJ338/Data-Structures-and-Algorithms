// leetcode - easy

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        if(root == NULL) return v;
        stack<TreeNode *>st;
        st.push(root->val);
        while(!st.empty()){
            if(root != NULL){
                st.push(root->val);
                root = root->left;
            }
            else{
                TreeNode* temp = st.top();
                root = temp;
                root = root->right;
                if(root == NULL){
                    
                }
            }
        }
    }
};
