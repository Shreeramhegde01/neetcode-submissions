class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target==nums[mid]) return mid;
            else if(nums[mid]>=nums[l]){
                if(target<nums[mid] and target>=nums[l]) h=mid-1;
                else l=mid+1;
            }
            else{
                if(target<=nums[h] and target>nums[mid]) l=mid+1;
                else h=mid-1;
            }
        }
        return -1;
    }
};
