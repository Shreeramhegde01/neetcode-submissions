class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tg=0,tc=0;
        int total=0,ans=0;
        for(int i=0;i<n;i++){
            tg+=gas[i];
            tc+=cost[i];
            total+=gas[i]-cost[i];
            if(total<0){
                ans=i+1;
                total=0;
            }
        }
        return tg>=tc?ans:-1;
    }
};