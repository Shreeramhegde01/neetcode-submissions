class Solution {
    void gen(vector<int>& nums, int t, int i, vector<vector<int>>& v, vector<int>& s){
        if(t==0){
            v.push_back(s);
            return;
        }
        if(t<0 or i==nums.size()) return;
        s.push_back(nums[i]);
        gen(nums,t-nums[i],i,v,s);
        s.pop_back();
        gen(nums,t,i+1,v,s);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        vector<int> s;
        gen(nums,target,0,v,s);
        return v;
    }
};
