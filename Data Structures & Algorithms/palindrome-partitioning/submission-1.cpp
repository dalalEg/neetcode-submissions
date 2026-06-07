class Solution {
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    void help(int index, string s, vector<string>& cur, int n) {
        if (index == s.size()){
            res.push_back(cur);
            return ;
        }
        for (int i = index; i < n; i++) {
            string sub = s.substr(index, i - index + 1);
            if (!isPalindrome(sub))
                continue;
            cur.push_back(sub);
            help(i + 1,s, cur, n);
            cur.pop_back();
        }
    }

public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        string t = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            t += s[i];
            if (!isPalindrome(t))
                continue;
            vector<string> curr;
            curr.push_back(t);
            help(i + 1, s, curr, n);
        }
        return res;
    }
};
