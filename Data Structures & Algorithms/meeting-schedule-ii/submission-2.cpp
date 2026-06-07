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
        vector<pair<int,int>> times;
        for(const auto& a :intervals ){
            times.push_back({a.start,1});
            times.push_back({a.end,-1});
        }
        sort(times.begin(),times.end(),[](auto&a,auto&b){return a.first==b.first ? 
        a.second<b.second:a.first<b.first;});
        int res=0,curr=0;
        for (const auto& time:times){
            curr+=time.second;
            res=max(res,curr);
        }
        return res;
    }
};
