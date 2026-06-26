class Solution {
    int f(vector<int>& nums, int i ,int n){
        int p1=0,p2=0;
        for(int j=i;j<=n;j++){
            int k=max(p1,nums[j]+p2);
            p2=p1;
            p1=k;
        }
        return p1;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(f(nums,0,n-2),f(nums,1,n-1));
    }
};
