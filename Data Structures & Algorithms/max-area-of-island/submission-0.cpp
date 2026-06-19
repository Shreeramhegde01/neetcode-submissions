class Solution {
    int dfs(int i, int j,vector<vector<int>>& board){
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j]==0) return 0;
        board[i][j]=0;
        int u=dfs(i+1,j,board);
        int d=dfs(i-1,j,board);
        int l=dfs(i,j-1,board);
        int r=dfs(i,j+1,board);
        return 1+u+d+l+r;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans=max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
};
