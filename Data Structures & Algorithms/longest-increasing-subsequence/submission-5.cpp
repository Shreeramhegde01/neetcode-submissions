class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> next(n+1,0),cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int l=next[prev+1];
                if(prev==-1 or nums[i]>nums[prev]){
                    l=max(l,1+next[i+1]);
                }
                cur[prev+1]=l;
            }
            next=cur;
        }
        return next[0];
    }
};