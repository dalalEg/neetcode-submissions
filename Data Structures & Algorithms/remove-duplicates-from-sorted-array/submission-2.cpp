class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> nums2(201,0);
        for(int num:nums){
            if (num<0){
                nums2[abs(num)+100]++;
            }
            else{
                nums2[num]++;
            }
        }
        int k=0;
        for(int i=200;i>=101;i--){
            if(nums2[i]>=1){
                nums[k]=100-i;
                k++;
            }
        }
        for(int i=0;i<=100;i++){
            if(nums2[i]>=1){
                nums[k]=i;
                k++;
            }
        }
      
        return k;
    }
};