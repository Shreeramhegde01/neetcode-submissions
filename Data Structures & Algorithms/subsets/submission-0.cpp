class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        auto ns=1<<nums.size();
        for(auto i=0;i<ns;i++){
            vector<int> t;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)) t.push_back(nums[j]);
            }
            ans.push_back(t);
        }
        return ans;
    }
};
