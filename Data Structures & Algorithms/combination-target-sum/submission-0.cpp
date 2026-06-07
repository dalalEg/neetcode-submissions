class Solution {
    void backtrack(int index, int sum, vector<int>& curr, vector<int>& nums,
                   vector<vector<int>>& output, int n, int target) {
        if (sum == target)
            output.push_back(curr);
        if (sum > target)
            return;
        for (int i = index; i < n; i++) {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            // Recurse to form the next combination
            sum += nums[i];
            backtrack(i, sum, curr, nums, output, n, target);
            // Backtrack and remove the last element
            curr.pop_back();
            sum -= nums[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> st;
        int n = nums.size();
        vector<int> curr;
        backtrack(0, 0, curr, nums, st, n,
                  target); // Call once to generate all subsets

        return st;
    }
};
