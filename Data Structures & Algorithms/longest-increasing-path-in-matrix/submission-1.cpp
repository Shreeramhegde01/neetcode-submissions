class Solution {
    vector<vector<int>> dp;
    int f(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>> &vis,int par){
        if(min(i,j)<0 or i>=matrix.size() or j>=matrix[0].size() or vis[i][j] or matrix[i][j]<=par) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        vis[i][j]=1;
        int l=f(matrix,i,j-1,vis,matrix[i][j]);
        int r=f(matrix,i,j+1,vis,matrix[i][j]);
        int u=f(matrix,i-1,j,vis,matrix[i][j]);
        int b=f(matrix,i+1,j,vis,matrix[i][j]);
        vis[i][j]=false;
        return dp[i][j]=1+max({l,r,u,b});
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dp.resize(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(matrix,i,j,vis,-1));
            }
        }
        return ans;
    }
};
