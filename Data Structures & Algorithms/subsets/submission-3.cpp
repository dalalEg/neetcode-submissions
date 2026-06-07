class Solution {
        vector<vector<int>> res;

public:
    void backtracking(vector<int>& nums , int i,vector<int> curr){
        if (i>=nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtracking(nums,i+1,curr);
        curr.pop_back();
        backtracking(nums,i+1,curr);

        


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtracking(nums,0,curr);
        return res;
    }
};
