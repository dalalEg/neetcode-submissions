class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for (string str : strs){
            vector<int> count(26,0);
            for(char s :str){
                count[s-'a']++;
            }
            string coding="";
            for (int i=0;i<26;i++){
                coding+=count[i]+'a';
            }
            mp[coding].push_back(str);
        }
         vector<vector<string>> res;
         for(auto& a:mp){
            res.push_back(a.second);
         }
         return res;
    }
};
