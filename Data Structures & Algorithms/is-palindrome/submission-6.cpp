class Solution {
public:
    bool isPalindrome(string s) {
        int l = s.length();
        int start = 0, end = l - 1;
        
        while (start <= end) {
            while (start < l && !isalnum(s[start])) {
                start++;
            }
            while (end >= 0 && !isalnum(s[end])) {
                end--;
            }

            if (start < l && end >= 0) {
                if (tolower(s[start]) != tolower(s[end])) {
                    return false;
                }
            }
            start++;
            end--;
        }
        
        return true;
    }
};