class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> st;
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int ans = 1;
        int longest = 1;
        auto it = st.begin(); // Iterator to the first element
        int prev = *it;
        auto next_it = next(it); // Iterator to the next element

        while (next_it != st.end()) {
            int next_value = *next_it;
            if (next_value == prev + 1) {
                longest++;
            } else {
                ans = max(longest, ans);
                longest=1;
            }
            prev = next_value;
            next_it = std::next(next_it); // Iterator to the next element
        }
        return max(longest, ans);
    }
};
