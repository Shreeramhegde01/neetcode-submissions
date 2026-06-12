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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        sh(root,s);
        return s;
    }
    void sh(TreeNode* root, string &s){
        if(!root){
            s+="! ";
            return;
        }
        s+=to_string(root->val)+" ";
        sh(root->left,s);
        sh(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()) return nullptr;
        stringstream s(data);
        TreeNode* root=dh(s);
        return root;
    }
    TreeNode* dh(stringstream &s){
        string v;
        s>>v;
        if(v=="!") return nullptr;
        TreeNode* root= new TreeNode(stoi(v));
        root->left=dh(s);
        root->right=dh(s);
        return root;
    }
};
