class Solution {
    int f(string &s, string &t, int i, int j,vector<vector<int>> &dp){
        if(j==t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            ans+=f(s,t,i+1,j+1,dp);
        }
        ans+=f(s,t,i+1,j,dp);
        return dp[i][j]=ans;
    }
public:
    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0;
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(s,t,0,0,dp);
    }
};
