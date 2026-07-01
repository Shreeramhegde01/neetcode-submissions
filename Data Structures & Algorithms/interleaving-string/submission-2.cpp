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
       vector<vector<int>> cur(s2.size()+2,vector<int>(s3.size()+2,0)), next(s2.size()+2,vector<int>(s3.size()+2,0));
        cur[s2.size()][s3.size()]=next[s2.size()][s3.size()]= 1;
        for(int i=s1.size();i>=0 ;i--){
            for(int j=s2.size();j>=0;j--){
                for(int k=s3.size();k>=0;k--){
                    if(i<s1.size() and k<s3.size() and s1[i]==s3[k] and next[j][k+1]) cur[j][k]=true;
                    if(j<s2.size() and k<s3.size() and s2[j]==s3[k] and cur[j+1][k+1]) cur[j][k]=true;
                }
            }
            next=cur;
        }
        return cur[0][0];
    }
};
