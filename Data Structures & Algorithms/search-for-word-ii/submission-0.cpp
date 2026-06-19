class Node{
    public:
    unordered_map<char,Node*> child;
    bool end=false;
    void add(string &s){
        Node* p=this;
        for(char& c:s){
            if(!p->child[c]) p->child[c]=new Node();
            p=p->child[c];
        }
        p->end=true;
    }
};
class Solution {
    vector<vector<bool>> vis;
    unordered_set<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *root = new Node();
        for(string& s:words){
            root->add(s);
        }
        int r=board.size(),c=board[0].size();
        vis.assign(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dfs(i,j,board,root,"");
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }

    void dfs(int i, int j, vector<vector<char>>& board, Node* root, string s){
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or vis[i][j] or !root->child.count(board[i][j])) return ;
        int r=board.size();
        int c=board[0].size();
        vis[i][j]=true;
        root=root->child[board[i][j]];
        s+=board[i][j];
        if(root->end) ans.insert(s);
        dfs(i,j+1,board,root,s);
        dfs(i+1,j,board,root,s);
        dfs(i-1,j,board,root,s);
        dfs(i,j-1,board,root,s);
        vis[i][j]=false;
    }
};
