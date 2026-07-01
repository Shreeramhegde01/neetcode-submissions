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
        vector<int> cur(amount+1,0);
        cur[0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
                if(j-coins[i]>=0){
                    cur[j]+=cur[j-coins[i]];
                }
            }
        }
        return cur[amount];
    }
};
