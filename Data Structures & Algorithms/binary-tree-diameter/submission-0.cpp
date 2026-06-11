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
    int f(TreeNode* root, int& m){
        if(!root) return 0;
        int l=f(root->left,m);
        int r=f(root->right,m);
        m=max(m,l+r);
        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return 0;
        int m=0;
        f(root,m);
        return m;
    }
};
