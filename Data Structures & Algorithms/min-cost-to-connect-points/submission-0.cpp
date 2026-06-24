class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        vector<bool> vis(n,false);
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        for(int i=0;i<n;i++){
            int u=-1;
            for(int j=0;j<n;j++){
                if(!vis[j] and (u==-1 or dist[j]<dist[u])) u=j;
            }
            vis[u]=true;
            ans+=dist[u];
            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int nd=abs(points[u][0]-points[v][0])+abs(points[v][1]-points[u][1]);
                    dist[v]=min(dist[v],nd);
                }
            }
        }
        return ans;
    }
};