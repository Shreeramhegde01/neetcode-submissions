class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) c++;
            }
        }
        if(c==0) return 0;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int ans=-1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto[x,y]=q.front();
                q.pop();
                for(auto& [dx,dy]:dir){
                    int nx=x+dx;
                    int ny=y+dy;
                    if(nx<0 or ny<0 or nx>=n or ny>=m or grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    c--; 
                    q.push({nx,ny});
                }
            }
            ans++;
        }
        if(c==0) return ans;
        return -1;
    }
};
