class Solution {
    void backtrack(int index, vector<int>& nums) {
        if (index == nums.size()) {
            output.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(index + 1, nums);
            swap(nums[index], nums[i]); // backtrack
        }
    }

public:
    vector<vector<int>> output;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return output;
    }
};