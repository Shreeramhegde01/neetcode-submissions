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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l=h(root->left);
        int r=h(root->right);
        if(abs(l-r)>1) return false;
        return isBalanced(root->left) and isBalanced(root->right);
    }
    int h(TreeNode* root){
        if(!root) return 0;
        return 1+max(h(root->left),h(root->right));
    }
};
