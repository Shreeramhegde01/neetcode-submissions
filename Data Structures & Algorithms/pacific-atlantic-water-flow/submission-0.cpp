class Solution {
    vector<vector<bool>> paci,atla;
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j, vector<vector<int>>& h, vector<vector<bool>>& vis){
        vis[i][j]=1;
        for(auto& [x,y]:dir){
            int nx=x+i;
            int ny=y+j;
            if(nx<0 or ny<0 or nx>=h.size() or ny>=h[0].size() or vis[nx][ny] or h[nx][ny]<h[i][j]) continue;
            dfs(nx,ny,h,vis);
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        paci.assign(n,vector<bool>(m,false));
        atla.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++) dfs(i,0,heights,paci);
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atla);
        for(int j=0;j<m;j++) dfs(0,j,heights,paci);
        for(int j=0;j<m;j++) dfs(n-1,j,heights,atla);
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(paci[i][j] and atla[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
