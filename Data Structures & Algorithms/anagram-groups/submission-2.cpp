class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mapping;
        for(string str:strs){
            vector<int> count(26,0);
            for(char st: str){
                count[st-'a']+=1;
            }
            string code="";
            for (int i=0;i<26;i++){
                code+=count[i]+'a';
            }
            mapping[code].push_back(str);

        }
        vector<vector<string>> res;
        for (auto a:mapping){
            vector<string>curr;
            for(string str:a.second){
                curr.push_back(str);
            }
            if(curr.size()>0)
                res.push_back(curr);
        }
        return res;
    }
};
