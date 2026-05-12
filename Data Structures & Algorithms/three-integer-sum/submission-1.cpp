class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int s=nums[i]+nums[j]+nums[k];
                if(s==0){ ans.push_back({nums[i],nums[j],nums[k]});j++,k--;
                while(nums[j]==nums[j-1]) j++;
                while(nums[k]==nums[k+1]) k--;}
                if(s<0) j++;
                if(s>0) k--;
            }
        }
        return ans;
    }
};
