class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s1=0,s2=0,f=0;
        while(1){
            s1=nums[s1];
            f=nums[nums[f]];
            if(s1==f) break;
        }
        while(1){
            s1=nums[s1];
            s2=nums[s2];
            if(s1==s2) return s1;
        }
        return 0;
    }
};
