class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        for (char task :tasks){
            count[task-'A']++;
        }
        priority_queue<int>pq;
        for (int cnt:count){
            if (cnt > 0){
                pq.push(cnt);
            } 
        }
        int cycles=0;
        queue<pair<int, int>> q;
        while( pq.size() || q.size()){
            if (pq.empty()){
                cycles=q.front().second;
            }else{
                int avail=pq.top()-1;
                pq.pop();
                if (avail>0){
                    q.push({avail,cycles+n});
                }
            }
              if (!q.empty() && q.front().second == cycles) {
                pq.push(q.front().first);
                q.pop();
            }
            cycles++;
        }
        return cycles;
    }
};
