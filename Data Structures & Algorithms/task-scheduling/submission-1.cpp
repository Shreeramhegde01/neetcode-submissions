class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> co(26);
        for(char c:tasks){
            co[c-'A']++;
        }
        int mxf=*max_element(co.begin(),co.end());
        int mc=0;
        for(int i:co){
            if(i==mxf) mc++;
        }
        int t=(mxf-1)*(n+1)+mc;
        int m=tasks.size();
        return max(t,m);
    }
};
