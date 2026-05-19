class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        vector<int> win(k);
        int m=-1e9;
        for(int i=0;i<k;i++){win[i]=nums[i];m=max(m,nums[i]);}
        ans.push_back(m);
        for(int i=k;i<n;i++){
            win[i%k]=nums[i];
            int m=-1e9;
            for(int &j:win) m=max(m,j);
            ans.push_back(m);
        }
        return ans;
    }
};
