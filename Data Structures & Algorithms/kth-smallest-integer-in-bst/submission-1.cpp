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
    void f(TreeNode* root,int k, int &c,int &a){
        if(!root) return ;
        f(root->left,k,c,a);
        c++;
        if(c==k){
            a=root->val;
            return;
        }
        f(root->right,k,c,a);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int a=0,c=0;
        f(root,k,c,a);
        return a;
    }
};
