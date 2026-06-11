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
    void f(TreeNode* root, int i,vector<int> &v){
        if(!root) return;
        if(i==v.size()) v.push_back(root->val);
        f(root->right,i+1,v);
        f(root->left,i+1,v);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        f(root,0,v);
        return v;
    }
};
