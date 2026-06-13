class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> co(26);
        for(char c:tasks){
            co[c-'A']++;
        }
        sort(co.begin(),co.end());
        int mxf=co[25];
        int time=(mxf-1)*n;
        for(int i=24;i>=0;i--){
            time-=min(mxf-1,co[i]);
        }
        return max(0,time)+tasks.size();
    }
};
