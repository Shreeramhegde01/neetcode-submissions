class Solution {
    int m,n;
    int f(int i, int j,vector<vector<int>> &dp){
        if(i==m-1 and j==n-1) return 1;
        if(i>=m or j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=f(i+1,j,dp)+f(i,j+1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]+= i<m-1?dp[i+1][j]:0;
                dp[i][j]+= j<n-1?dp[i][j+1]:0;
            }
        }
        return dp[0][0];
    }
};
