class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1);
        int res=1;
        for (int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if (nums[i]<nums[j]){
                    lis[i]=max(lis[j]+1,lis[i]);
                    res=max(res,lis[i]);
                }
            }
        }
            return res;

    }
};
