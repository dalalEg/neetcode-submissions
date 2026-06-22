class Solution {
    void dfs(vector<int>& nums, int i, vector<int> curr,vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);

        dfs(nums, i + 1, curr, res);
        curr.pop_back();
        dfs(nums, i + 1, curr, res);
    }

   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
};
