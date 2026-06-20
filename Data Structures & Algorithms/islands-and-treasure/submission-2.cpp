class Solution {
public:
void islandsAndTreasure(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                q.push({i,j});
            }
        }
    }
    int arr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        for(auto [dx,dy]:arr){
            int nx=x+dx;
            int ny=y+dy;
            if(nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]==-1 or grid[nx][ny]!=INT_MAX) continue;
            grid[nx][ny]=1+grid[x][y];
            q.push({nx,ny});
        }
    }
}
};
