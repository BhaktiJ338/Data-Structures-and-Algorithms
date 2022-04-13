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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int hl = maxDepth(root->left);
        int hr = maxDepth(root->right);
        return max(hl, hr)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int hleft = maxDepth(root->left);
        int hright = maxDepth(root->right);
        if(abs(hleft-hright) > 1) return false;
        bool leftb= isBalanced(root->left);
        bool rightb= isBalanced(root->right);
        
        if(!leftb || !rightb) return false;
        return true;
    }
};
