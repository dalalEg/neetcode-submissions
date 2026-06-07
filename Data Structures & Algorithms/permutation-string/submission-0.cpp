class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> count1(26, 0), count2(26, 0);
        for (char ch : s1) {
            count1[ch - 'a']++;
        }

        // Initialize the first window
        for (int i = 0; i < n1; ++i) {
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        // Slide the window
        for (int i = n1; i < n2; ++i) {
            count2[s2[i] - 'a']++;              // add new char
            count2[s2[i - n1] - 'a']--;         // remove old char
            if (count1 == count2) return true;  // compare counts
        }

        return false;
    }
};
