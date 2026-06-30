class Solution {
    bool f(vector<int>&nums, vector<vector<int>>& dp, int target, int i){
        if(target==0) return true;
        if(i==nums.size() or target<0) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target]=f(nums,dp,target-nums[i],i+1) or f(nums,dp,target,i+1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(nums,dp,target,0);
    }
};
