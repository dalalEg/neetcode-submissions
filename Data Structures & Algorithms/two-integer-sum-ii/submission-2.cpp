class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size(),left=0,right =n-1;
        vector<int> res(2,0);
        while(left<right){
            int sum =numbers[left]+numbers[right];
            if(sum==target){
                res[0]=left+1;
                res[1]=right+1;
                break;
            }else if(sum < target){
                left++;
            } else{
                right--;
            }
        }
        return res;
    }
};
