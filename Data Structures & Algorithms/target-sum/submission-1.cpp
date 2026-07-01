class Solution {
    int t;
    int s;
    int f(int i,vector<int>& nums, int sum,vector<vector<int>>& dp){
        if(i==nums.size()) return sum==t;
        if(dp[i][sum+s]!=-1) return dp[i][sum+s];
        int pos=f(i+1,nums,sum-nums[i],dp);
        int neg=f(i+1,nums,sum+nums[i],dp);
        return dp[i][sum+s]=pos+neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t=target;
        int n=nums.size();
        s=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*s+2,-1));
        return f(0,nums,0,dp);
    }
};
