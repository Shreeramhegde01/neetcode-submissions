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
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j){
                    dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
