class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char ch : s) {
            if (closeToOpen.find(ch) != closeToOpen.end()) {
                if (st.empty() || closeToOpen[ch] != st.top() ) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
