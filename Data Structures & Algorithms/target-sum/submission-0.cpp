class Solution {
    int t;
    int f(int i,vector<int>& nums, int sum){
        if(i==nums.size()) return sum==t;
        int pos=f(i+1,nums,sum-nums[i]);
        int neg=f(i+1,nums,sum+nums[i]);
        return pos+neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        t=target;
        return f(0,nums,0);
    }
};
