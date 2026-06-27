class Solution {
    // int f(string &s, int i,vector<int>& dp){
    //     if(i>=s.size()) return 1;
    //     if(s[i]=='0') return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int ans=f(s,i+1,dp);
    //     if(i<s.size()-1)
    //         if(s[i]=='1' or (s[i]=='2' and s[i+1]<'7')) ans+=f(s,i+2,dp);
    //     return dp[i]=ans;
    // }
public:
    int numDecodings(string s) {
        int dp=0,dp1=1,dp2=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0') dp=0;
            else{
                dp=dp1;
                if(i+1<s.size() and (s[i]=='1' or(s[i]=='2' and s[i+1]<'7'))) dp+=dp2;
            }
            dp2=dp1;
            dp1=dp;
        }
        return dp;
    }
};