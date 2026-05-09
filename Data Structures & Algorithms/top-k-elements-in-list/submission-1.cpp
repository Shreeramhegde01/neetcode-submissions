class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int &i:nums) mpp[i]++;
        vector<pair<int,int>> v;
        for(auto &it:mpp) v.push_back({it.second,it.first});
        sort(v.begin(),v.end(),[](auto &a, auto &b){
            return a.first>b.first;
        });
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].second);
        return ans;
    }
};
