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
        if(!root) return 1;
        int l=f(root->left);
        int r=f(root->right);
        if(abs(l-r)>1) return 0;
        return isBalanced(root->right) and isBalanced(root->left);
    }
    int f(TreeNode* root){
        if(!root) return 0;
        return max(f(root->left),f(root->right))+1;
    }
};
