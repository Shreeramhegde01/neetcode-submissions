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
        f(root,s);
        return s;
    }
    void f(TreeNode* root, string &s){
        if(!root) {s+="! "; return;}
        s+=to_string(root->val)+" ";
        f(root->left,s);
        f(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()) return nullptr;
        stringstream s(data);
        return d(s);
    }
    TreeNode* d(stringstream &s){
        string v;
        s>>v;
        if(v=="!") return nullptr;
        TreeNode* root= new TreeNode(stoi(v));
        root->left=d(s);
        root->right=d(s);
        return root;
    }
};
