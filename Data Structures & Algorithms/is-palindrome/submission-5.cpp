class Solution {
   public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < r && !isNumOrLetter(s[l])) {
                l++;
            }
            while (r > l && !isNumOrLetter(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])){ return false;}
            l++;
            r--;
        }
        return true;
    }
    bool isNumOrLetter(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
    }
};
