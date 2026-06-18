class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        f(v,sub,nums,0);
        return v;
    }
    void f(vector<vector<int>>& v, vector<int>& sub, vector<int>& nums, int i){
        v.push_back(sub);
        for(int j=i;j<nums.size();j++){
            if(j>i and nums[j]==nums[j-1]) continue;
            sub.push_back(nums[j]);
            f(v,sub,nums,j+1);
            sub.pop_back();
        }
    }
};
