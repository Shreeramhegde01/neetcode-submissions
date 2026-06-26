class Solution {
    int f(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(f(nums,i+1,dp),nums[i]+f(nums,i+2,dp));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int p1=0,p2=0;    
        for(int i=0;i<n;i++){
            int k=max(p1,nums[i]+p2);
            p2=p1;
            p1=k;
        }
        return p1;
    }
};
