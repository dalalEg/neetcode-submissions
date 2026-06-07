class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(const string str:strs ){
            string temp=str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto a:mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};
