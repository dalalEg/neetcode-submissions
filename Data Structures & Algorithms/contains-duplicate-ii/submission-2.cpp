class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(const auto& [first,second] :mp){
            if(second.size()==1)
                continue;
            int l=second[0];
            for(int i=1;i<second.size();i++){
                if(second[i]-l<=k){
                    return true;
                }else{
                    l=second[i];
                }


            }
        }
        return false;
    }
};