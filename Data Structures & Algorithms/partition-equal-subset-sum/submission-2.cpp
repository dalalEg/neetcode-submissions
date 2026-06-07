class Solution {
public:
    bool backtracking(vector<int>& nums,int i , int sum,int target){
        if(sum==target)
            return true;
        if (i>=nums.size())
            return false;
        return backtracking(nums,i+1,sum+nums[i],target)or backtracking(nums,i+1,sum,target);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum%2!=0)
            return false;
        
        return  backtracking(nums,0,0,sum/2);   
        }
};
