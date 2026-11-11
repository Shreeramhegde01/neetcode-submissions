/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start,end;
        for(auto &it:intervals){
            start.push_back(it.start);
            end.push_back(it.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int ans=0,count=0,s=0,e=0;
        while(s<end.size()){
            if(start[s]<end[e]){
                s++;
                count++;
            }
            else{
                e++;
                count--;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
