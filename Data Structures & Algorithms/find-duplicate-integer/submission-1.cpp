class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0,slow2=0;
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow) break;
        }
        while(1){
            slow2=nums[slow2];
            slow=nums[slow];
            if(slow==slow2) return slow;
        }
        return 0;
    }
};
