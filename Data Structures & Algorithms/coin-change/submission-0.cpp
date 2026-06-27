class Solution {
    int f(vector<int>&coins, int amount,vector<int>& dp){
        if(amount==0) return 0;
        if(amount<0) return 1e9;
        if(dp[amount]!=-1) return dp[amount];
        int ans=1e9;
        for(int coin:coins){
                int res=f(coins,amount-coin,dp);
                if(res!=1e9) ans=min(ans,1+res);
        }
        return dp[amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=f(coins,amount,dp);
        return ans>=1e9?-1:ans;
    }
};
