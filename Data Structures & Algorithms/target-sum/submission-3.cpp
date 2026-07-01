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
        if(abs(target)>s) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2*s+1,0));
        dp[n][target+s]=1;
        for(int i=n-1;i>=0;i--){
            for(int sum=-s;sum<=s;sum++){
                int ways=0;
                if(sum-nums[i]>=-s) ways+=dp[i+1][sum-nums[i]+s];
                if(sum+nums[i]<=s) ways+=dp[i+1][sum+nums[i]+s];
                dp[i][sum+s]=ways;
            }
        }
        return dp[0][s];
    }
};
