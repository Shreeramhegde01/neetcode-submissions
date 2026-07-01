class Solution {
    int f(int amount,vector<int>& coins, int i,vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(i>=coins.size() or amount<0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int nottake=f(amount,coins,i+1,dp);
        int take=0;
        if(amount-coins[i]>=0)
            take=f(amount-coins[i],coins,i,dp);
        return dp[i][amount]=take+nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return f(amount,coins,0,dp);
    }
};
