class Solution {
    int f(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(f(nums,i+1,dp),nums[i]+f(nums,i+2,dp));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(nums,0,dp);
    }
};
