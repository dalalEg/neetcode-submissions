class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int curMax = 1, res = INT_MIN,curMin=1;
       for (int num:nums) {
           int tmp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(tmp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
