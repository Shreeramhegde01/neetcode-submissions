class Solution {
    bool f(int i,int j, int k, string& s1, string &s2, string &s3,vector<vector<vector<int>>> &dp){
        if(k==s3.size()) return i==s1.size() and j==s2.size();
        if(i<s1.size() and j<s2.size() and k<s3.size() and dp[i][j][k]!=-1) return dp[i][j][k];
        if(i<s1.size() and s1[i]==s3[k]){
            if(f(i+1,j,k+1,s1,s2,s3,dp)) return dp[i][j][k] = true;
        }
        if(j<s2.size() and s2[j]==s3[k]){
            if(f(i,j+1,k+1,s1,s2,s3,dp)) return dp[i][j][k] = true;
        } 
        return dp[i][j][k]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size();
        vector<int> cur(m+2,0),next(m+2,0);
        if(s3.size()!=s1.size()+s2.size()) return false;
        cur[m]=next[m]=1;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m)
                    continue;
                cur[j]=0;
                int k=i+j;
                if(i<n && s1[i]==s3[k])
                    cur[j]|=next[j];
                if(j<m && s2[j]==s3[k])
                    cur[j]|=cur[j+1];
                }
                next=cur;
            }
        return next[0];
    }
};
