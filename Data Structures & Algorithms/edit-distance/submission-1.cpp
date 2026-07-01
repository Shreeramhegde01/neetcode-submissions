class Solution {
    int f(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=f(s1,s2,i-1,j-1,dp);
        int l=f(s1,s2,i-1,j,dp);
        int m=f(s1,s2,i-1,j-1,dp);
        int n=f(s1,s2,i,j-1,dp);
        return dp[i][j]=1+min({l,m,n});
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else {
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return  dp[n][m];
    }
};
