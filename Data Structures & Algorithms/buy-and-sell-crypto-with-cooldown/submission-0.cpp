class Solution {
    int f(vector<int>& prices,int i, vector<vector<int>> &dp, int buy){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(prices,i+1,dp,0),f(prices,i+1,dp,1));
        }
        return dp[i][buy]=max(prices[i]+f(prices,i+2,dp,1),f(prices,i+1,dp,0));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,dp,1);
    }
};
