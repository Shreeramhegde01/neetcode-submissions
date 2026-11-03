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
    unordered_map<int,int> mpp;
    TreeNode* f(int ps,int pe, vector<int>& preorder, int is, int ie, vector<int>& inorder){
        if(is>ie or ps>pe) return nullptr;
        TreeNode* root= new TreeNode(preorder[ps]);
        int inIndex=mpp[root->val];
        int leftfreq=inIndex-is;
        root->left=f(ps+1,ps+leftfreq,preorder,is,inIndex-1,inorder);
        root->right=f(ps+1+leftfreq,pe,preorder,inIndex+1,ie,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        return f(0,n-1,preorder,0,n-1,inorder);
    }
};
