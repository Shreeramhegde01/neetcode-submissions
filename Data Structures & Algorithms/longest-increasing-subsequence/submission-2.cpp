class Solution {
    int n;
    int rec(int idx,int prev_idx,vector<int>& nums, vector<vector<int>>& dp){
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int l=rec(idx+1,prev_idx,nums,dp);
        if(prev_idx==-1 or nums[idx]>nums[prev_idx]){
            l=max(l,1+rec(idx+1,idx,nums,dp));
        }
        return dp[idx][prev_idx+1]=l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return rec(0,-1,nums,dp);
    }
};
