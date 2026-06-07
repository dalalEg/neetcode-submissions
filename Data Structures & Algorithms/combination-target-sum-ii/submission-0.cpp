class Solution {
 void dfs(int i, vector<int>& cur, int total, vector<int>& nums, int target) {
    if (total == target) {
        res.push_back(cur);
        return;
    }

    for (int j = i; j < nums.size(); j++) {
        // 🔁 Skip duplicates at the same recursive level
        if (j > i && nums[j] == nums[j - 1]) continue;

        if (total + nums[j] > target) break;

        cur.push_back(nums[j]);
        dfs(j + 1, cur, total + nums[j], nums, target);
        cur.pop_back();
    }
}
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(0, curr, 0, candidates, target);
        return res;
    }
};


