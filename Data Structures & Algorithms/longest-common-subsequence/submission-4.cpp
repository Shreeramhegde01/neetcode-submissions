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
        vector<int> cur(m+1,0),next(m+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]) next[j+1]=1+cur[j];
                else next[j+1]=max(next[j],cur[j+1]);
            }
            cur=next;
        }
        return next[m];
    }
};
