class Solution {
    int f(string &s, int i,vector<int>& dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=f(s,i+1,dp);
        if(i<s.size()-1)
            if(s[i]=='1' or (s[i]=='2' and s[i+1]<'7')) ans+=f(s,i+2,dp);
        return dp[i]=ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                dp[i]=dp[i+1];
                if(i+1<s.size() and (s[i]=='1' or(s[i]=='2' and s[i+1]<'7'))) dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};