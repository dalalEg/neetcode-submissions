class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // initial window
        for (int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        // sliding window
        for (int j = n; j < m; j++) {
            count2[s2[j] - 'a']++;
            count2[s2[j - n] - 'a']--;
            if (count1 == count2) return true;
        }

        return false;
    }
};