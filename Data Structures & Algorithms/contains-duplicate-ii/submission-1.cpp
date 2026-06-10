class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(const auto& a :mp){
            if(a.second.size()==1)
                continue;
            int l=a.second[0];
            for(int i=1;i<a.second.size();i++){
                if(a.second[i]-l<=k){
                    return true;
                }else{
                    l=a.second[i];
                }


            }
        }
        return false;
    }
};