class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mj=0;
        for(int i=0;i<nums.size();i++){
            if(i>mj) return false;
            mj=max(mj,i+nums[i]);
        }
        return true;
    }
};
