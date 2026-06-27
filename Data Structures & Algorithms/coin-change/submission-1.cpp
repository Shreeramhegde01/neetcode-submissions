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
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
