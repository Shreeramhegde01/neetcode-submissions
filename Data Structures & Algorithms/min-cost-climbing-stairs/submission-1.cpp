class Solution {
    int f(int i,vector<int> &dp, vector<int>&cost){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(f(i+1,dp,cost),f(i+2,dp,cost));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(f(0,dp,cost),f(1,dp,cost));
    }
};
