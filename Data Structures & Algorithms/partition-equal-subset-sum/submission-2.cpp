class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tots=accumulate(nums.begin(),nums.end(),0);
        if(tots&1) return false;
        int halfs=tots/2;
        vector<bool> dp(halfs+1,false);
        dp[0]=true;
        for(int &n:nums){
            for(int cs=halfs;cs>=n;cs--){
                dp[cs]=dp[cs] || dp[cs-n];
            }
        }
        return dp[halfs];
    }
};