class Solution {
    vector<int> dp;
    
    int robRange(int i, int end, vector<int>& nums) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];
        
        int take = nums[i] + robRange(i + 2, end, nums);
        int skip = robRange(i + 1, end, nums);
        
        return dp[i] = max(take, skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Rob from 0 to n-2
        dp.assign(n, -1);
        int rob1 = robRange(0, n - 2, nums);

        // Rob from 1 to n-1
        dp.assign(n, -1);
        int rob2 = robRange(1, n - 1, nums);

        return max(rob1, rob2);
    }
};
