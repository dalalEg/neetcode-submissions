class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1)
            return true;
        if(nums[0]==0)
            return false;
        int maxIndex=nums[0];
        for(int i=1;i<nums.size();i++){
            if(maxIndex>=nums.size()-1)
                return true;
            if (i > maxIndex)
                return false;
            maxIndex=max(maxIndex,nums[i]+i);
        }
        return maxIndex>=(nums.size()-1);
    }
};
