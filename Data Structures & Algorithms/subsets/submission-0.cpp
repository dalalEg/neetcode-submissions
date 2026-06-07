class Solution {
    void generateSubsets(int index,vector<int>curr, vector<int>& nums, vector<vector<int>>& output,int n){
       output.push_back(curr);
       for(int i=index;i<n;i++){
        curr.push_back(nums[i]);
            // Recurse to form the next combination
            generateSubsets(i + 1, curr, nums,output,n);
            // Backtrack and remove the last element
            curr.pop_back();
       }
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();
        vector<int> curr;
        generateSubsets(0, curr, nums,output,n); // Call once to generate all subsets
        return output;

    }
};
