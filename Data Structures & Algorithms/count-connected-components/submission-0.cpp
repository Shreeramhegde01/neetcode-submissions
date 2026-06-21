class Solution {
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int par){
        if(vis[i]) return;
        vis[i]=true;
        for(auto &it:adj[i]){
            if(it==par) continue;
            dfs(it,adj,vis,i);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,-1);
                ans++;
            }
        }
        return ans;
    }
};
