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
        vector<int> cur(t.size()+1,0);
        cur[t.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<t.size();j++){
                if(s[i]==t[j]) cur[j]+=cur[j+1];
            }
        }
        return cur[0];
    }
};
