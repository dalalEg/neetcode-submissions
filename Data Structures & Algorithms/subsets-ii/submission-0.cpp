class Solution {
    void generate(int index, vector<int>&curr,vector<int>&nums,int n){
        if(index>n)
            return;
        result.push_back(curr);
        for(int i=index;i<n;i++){
            if(i>index&&nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);
            generate(i+1,curr,nums,n);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> curr;
        generate(0,curr,nums,n);
        return result;
    }
};
