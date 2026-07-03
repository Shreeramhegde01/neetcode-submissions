class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=1;
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> ni=intervals[0];
        while(i<n){
            if(intervals[i][0]>ni[1]){
                ans.push_back(ni);
                ni=intervals[i];
            }
            else{
                ni[1]=max(ni[1],intervals[i][1]);
            }
            i++;
        }
        ans.push_back(ni);
        return ans;
    }
};
