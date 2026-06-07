class Solution {
    int f(vector<int>&piles,int hours){
        int tot=0;
        for(int i:piles){
            tot += (i + hours - 1) / hours;
        }
        return tot;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int t=f(piles,mid);
            if(t<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
