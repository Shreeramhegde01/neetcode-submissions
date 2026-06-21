class Solution {
    bool dfs(vector<vector<int>>& adj, int i, int par,vector<bool>& vis){
        if(vis[i]) return false;
        vis[i]=true;
        bool ok=true;
        for(auto it:adj[i]){
            if(it==par) continue;
            ok=ok&dfs(adj,it,i,vis);
        }
        return ok;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       for(auto &it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
       }
       vector<bool>vis(n,false);
       bool ok=dfs(adj,0,-1,vis);
       for(bool i:vis) ok=i&ok;
       return ok;
    }
};
