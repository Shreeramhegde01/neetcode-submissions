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
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a.start<b.start;
        });
        for(auto &it:intervals){
            if(pq.size() and pq.top()<=it.start) pq.pop();
            pq.push(it.end);
        }
        return pq.size();
    }
};
