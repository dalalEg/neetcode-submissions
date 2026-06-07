class Solution {
    void backtrack(int index, int sum, vector<int>& curr, vector<int>& nums,
                   vector<vector<int>>& output, int n, int target) {
        if (sum == target){
            output.push_back(curr);
            return ;}
        if (sum > target || index==n)
            return;
            if (index > 0 && nums[index] == nums[index - 1] && sum == 0) return;

            curr.push_back(nums[index]);
            // Recurse to form the next combination
            sum += nums[index];
            backtrack(index, sum, curr, nums, output, n, target);
            // Backtrack and remove the last element
            curr.pop_back();
            sum -= nums[index];
                        backtrack(index+1, sum, curr, nums, output, n, target);

       
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(0, 0, curr, nums, res, nums.size(), target);
    return res;
}

};
