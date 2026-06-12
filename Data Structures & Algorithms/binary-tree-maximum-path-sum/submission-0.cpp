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
    int f(TreeNode* root, int &m){
        if(!root) return 0;
        int l=max(0,f(root->left,m));
        int r=max(0,f(root->right,m));
        m=max(m,l+r+root->val);
        return max(l,r)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
};
