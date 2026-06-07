class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> minHeap;
         for(vector<int>&point :points){
            int dist = point[0]*point[0]+point[1]*point[1];
            minHeap.push({dist,point});
         }
          vector<vector<int>> res;
          while(k>0&&!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
            k--;
          }
          return res;

    }
};
