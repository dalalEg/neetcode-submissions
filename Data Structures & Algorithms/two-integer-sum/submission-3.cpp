class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            int num = nums[i];
            if(mp.find(target-num)!=mp.end()){
                return {mp[target-num], i};
            }
            mp[num]=i;
        }
        return {};
    }
};
