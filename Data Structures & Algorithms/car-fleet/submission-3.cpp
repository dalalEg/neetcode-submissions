class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        
        // pair positions with speeds
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        // sort cars by position descending (closest to target first)
        sort(cars.rbegin(), cars.rend());
        
        stack<double> st;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            
            // if current car catches up to fleet ahead, merge
            if (!st.empty() && time <= st.top()) {
                // do nothing, merges into fleet
            } else {
                st.push(time);
            }
        }
        
        return st.size();
    }
};