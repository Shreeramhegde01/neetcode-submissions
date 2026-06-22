class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> ind(n+1,0);
        vector<vector<int>> adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            ind[it[1]]++;
            ind[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n+1;i++) if(ind[i]==1) q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ind[node]--;
            for(auto i:adj[node]){
                ind[i]--;
                if(ind[i]==1) q.push(i);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(ind[edges[i][0]]==2 and ind[edges[i][1]]) return{edges[i][0],edges[i][1]};
        }
        return {};
    }
};
