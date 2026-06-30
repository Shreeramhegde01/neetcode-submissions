class Solution {
    int f(string &s1, string& s2, int i , int j,vector<vector<int>> &dp){
        if(i==0 and j==0) return s1[0]==s2[0];
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+f(s1,s2,i-1,j-1,dp);
        return dp[i][j]=max(f(s1,s2,i,j-1,dp),f(s1,s2,i-1,j,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(text1,text2,n-1,m-1,dp);
    }
};
