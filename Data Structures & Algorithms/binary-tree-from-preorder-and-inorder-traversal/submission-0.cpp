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
public:
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            mpp[in[i]]=i;
        }
        TreeNode* root= f(0,p.size()-1,p,0,in.size()-1,in);
        return root;
    }
    TreeNode* f(int ps,int pe,vector<int>&p, int is,int ie,vector<int>& in){
        if(is>ie or ps>pe) return nullptr;
        TreeNode* root= new TreeNode(p[ps]);
        int inr=mpp[root->val];
        int inf=inr-is;
        root->left=f(ps+1,ps+inf,p,is,inr-1,in);
        root->right=f(ps+1+inf,pe,p,inr+1,ie,in);
        return root;
    }
};
