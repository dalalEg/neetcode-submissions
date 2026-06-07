class Solution {
public:

    string encode(vector<string>& strs) {
        string ans ="";
        for(string str:strs){
            ans+=str;
            ans+= '\x80';
        }
        return ans;
    }

    vector<string> decode(string s) {
           vector<string> ans;
           string temp="";
           for(int i=0;i<s.size();i++){
             if(s[i]=='\x80'){
                ans.push_back(temp);
                temp="";
             }else{
                temp+=s[i];
             }
           }

           return ans; 
    }
};
