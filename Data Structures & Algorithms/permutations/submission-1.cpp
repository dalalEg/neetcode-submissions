class Solution {
    vector<vector<int>> output;

    void generatePermutations(vector<int>& nums, vector<int>& curr, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            output.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);

            generatePermutations(nums, curr, used);

            // backtrack
            curr.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        generatePermutations(nums, curr, used);
        return output;
    }
};
