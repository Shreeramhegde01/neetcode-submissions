class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i=1,n=intervals.size(),ans=0;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });
        int lastlargest=intervals[0][1];
        while(i<n){
            if(intervals[i][0]>=lastlargest){
                lastlargest=intervals[i][1];
            }
            else {
                ans++;
            }
            i++;
        }
    return ans;
    }
};
