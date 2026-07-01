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
        vector<int> cur(t.size()+1,0),next(t.size()+1,0);
        cur[t.size()]=next[t.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                cur[j]=0;
                if(s[i]==t[j]){
                    cur[j]=next[j+1];
                }
                cur[j]+=next[j];
            }
            next=cur;
        }
        return cur[0];
    }
};
