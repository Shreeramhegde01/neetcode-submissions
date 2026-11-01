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
    bool iss(TreeNode* p, TreeNode* q){
        if(!p or !q) return p==q;
        return p->val==q->val and iss(p->left,q->left) and iss(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        if(iss(root,subRoot)) return 1;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};
