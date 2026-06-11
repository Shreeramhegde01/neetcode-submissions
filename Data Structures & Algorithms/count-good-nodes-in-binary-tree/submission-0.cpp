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
    void f(TreeNode* root,int &c,int m){
        if(!root) return;
        if(root->val>=m) c++;
        m=max(root->val,m);
        f(root->left,c,m);
        f(root->right,c,m);
    }
public:
    int goodNodes(TreeNode* root) {
        int c=0;
        f(root,c,INT_MIN);
        return c;
    }
};
