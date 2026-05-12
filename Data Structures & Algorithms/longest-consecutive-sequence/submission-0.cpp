class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int ans=0;
        for(int it:s){
            if(s.find(it-1)==s.end()){
                int k=it;
                while(s.count(k++)) 
                ans=max(ans,k-it);
            }
        }
        return ans;
    }
};
