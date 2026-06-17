class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (l == nums.size() || nums[l] != target) return {-1, -1};
        int l2 = 0, r2 = nums.size();
        while (l2 < r2) {
            int m = l2 + (r2 - l2) / 2;
            if (nums[m] < target + 1) {
                l2 = m + 1;
            } else {
                r2 = m;
            }
        }

        return {l, l2 - 1};
    }
};