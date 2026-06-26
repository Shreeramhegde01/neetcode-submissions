class Solution {
    int f(vector<int>& nums, int i ,int n, vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(f(nums,i+1,n,dp),nums[i]+f(nums,i+2,n,dp));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n,-1),dp1(n,-1);
        return max(f(nums,0,n-1,dp),f(nums,1,n,dp1));
    }
};
