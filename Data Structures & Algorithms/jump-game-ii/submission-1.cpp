class Solution {
    int f(int i, int jump, vector<int>& nums,vector<vector<int>> &dp){
        if(i>=nums.size()-1) return jump;
        if(dp[i][jump]!=-1) return dp[i][jump];
        int minj=INT_MAX;
        for(int k=1;k<=nums[i];k++){
            minj=min(minj,f(i+k,jump+1,nums,dp));
        }
        return dp[i][jump]=minj;
    }
public:
    int jump(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return f(0,0,nums,dp);
    }
};
