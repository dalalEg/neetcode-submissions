#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // Using unordered_map for better performance
        for (int num : nums) {
            count[num]++;
        }

        // Define a min heap (priority_queue sorting by frequency in ascending order)
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // Min heap - higher frequency items stay at bottom
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> sorted(cmp);

        // Maintain a heap of size k
        for (const auto& entry : count) {
            sorted.push(entry);
            if (sorted.size() > k) sorted.pop(); // Remove least frequent elements
        }

        vector<int> ans;
        while (!sorted.empty()) {
            ans.push_back(sorted.top().first);
            sorted.pop();
        }
        return ans;
    }
};