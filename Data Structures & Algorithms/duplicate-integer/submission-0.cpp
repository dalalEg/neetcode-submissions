class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
          
            if(++mp[num]>1)
                return true;
        }
        return false;
    }
};
