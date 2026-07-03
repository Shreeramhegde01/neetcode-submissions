class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        unordered_map<int,int> mpp;
        for(int &i:hand) mpp[i]++;
        sort(hand.begin(),hand.end());
        for(int &n:hand){
            if(mpp[n]>0){
                for(int i=n;i<n+groupSize;i++){
                    if(mpp[i]==0) return false;
                    mpp[i]--;
                }
            }
        }
        return true;
    }
};
