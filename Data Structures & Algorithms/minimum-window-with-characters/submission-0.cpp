class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";

        vector<int> count(26, 0), count2(26, 0);  // lowercase, uppercase
        for (char ch : t) {
            if (ch >= 'a' && ch <= 'z') count[ch - 'a']++;
            else if (ch >= 'A' && ch <= 'Z') count2[ch - 'A']++;
        }

        vector<int> c(26, 0), c2(26, 0);  // current window counts
        int left = 0, right = 0, size = INT_MAX;
        int totalChars = 0, matched = 0;

        // calculate total characters needed
        for (int i = 0; i < 26; ++i)
            totalChars += count[i] + count2[i];

        string res = "";

        while (right < s.size()) {
            char ch = s[right];
            if (ch >= 'a' && ch <= 'z') {
                if (count[ch - 'a'] > 0) {
                    if (c[ch - 'a'] < count[ch - 'a']) matched++;
                    c[ch - 'a']++;
                }
            } else if (ch >= 'A' && ch <= 'Z') {
                if (count2[ch - 'A'] > 0) {
                    if (c2[ch - 'A'] < count2[ch - 'A']) matched++;
                    c2[ch - 'A']++;
                }
            }
            right++;

            // Try to contract the window
            while (matched == totalChars) {
                if (right - left < size) {
                    size = right - left;
                    res = s.substr(left, size);
                }

                char lc = s[left];
                if (lc >= 'a' && lc <= 'z') {
                    if (count[lc - 'a'] > 0) {
                        c[lc - 'a']--;
                        if (c[lc - 'a'] < count[lc - 'a']) matched--;
                    }
                } else if (lc >= 'A' && lc <= 'Z') {
                    if (count2[lc - 'A'] > 0) {
                        c2[lc - 'A']--;
                        if (c2[lc - 'A'] < count2[lc - 'A']) matched--;
                    }
                }
                left++;
            }
        }

        return res;
    }
};