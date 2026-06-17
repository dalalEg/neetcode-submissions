class Solution {
   public:
    string simplifyPath(string path) {
        string curr;
        vector<string> st;
        for (char c : path + "/") {
            if (c == '/') {
                if (curr == "..") {
                    if (!st.empty()) st.pop_back();
                } else if (!curr.empty() && curr != ".") {
                    st.push_back(curr);
                }
                curr.clear();
            } else {
                curr += c;
            }
        }
        string res = "";
        for (string s : st) {
            res += '/';
            res += s;
        }
        return res=="" ? "/":res;
    }
};