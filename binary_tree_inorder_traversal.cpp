// leetcode - easy

//recursive
class Solution {
private:
    void inorder(TreeNode* node, vector<int>&v){
        if(node == NULL) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>v;
        inorder(root, v);
        return v;
    }
};

// non-recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //stack<TreeNode*>st;
        vector<int>ans;
        TreeNode *curr = root, *prev = NULL;
        while(curr){
            if(curr->left == NULL){
                prev = curr;
                curr = curr->left;
            }
            else{
                //if(st.empty()) break;
                curr = prev;
                //st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
