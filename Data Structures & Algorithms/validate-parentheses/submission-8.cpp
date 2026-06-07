class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(char ss:s){
            if(closeToOpen.find(ss)!=closeToOpen.end()){
                if(stk.empty() || closeToOpen[ss]!=stk.top())
                    return false;
                stk.pop();
            }
            else
                stk.push(ss);
        }
        return stk.empty();
    }
};
