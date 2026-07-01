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
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i+1][j];
                if(j-coins[i]>=0){
                    dp[i][j]+=dp[i][j-coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};
