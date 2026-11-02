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
    int c=0;
    void f(TreeNode* root, int m){
        if(!root) return;
        if(root->val>=m) c++;
        m=max(m,root->val);
        f(root->left,m);
        f(root->right,m);
    }
public:
    int goodNodes(TreeNode* root) {
        f(root,-100);
        return c;
    }
};
