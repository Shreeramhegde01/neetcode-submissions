class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            if(mpp.count(target-nums[i]) and mpp[target-nums[i]]!=i) return {i,mpp[target-nums[i]]};
        }
        return {};
    }
};
