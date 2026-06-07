class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            // 1-digit decode is possible if s[i] != '0'
            if (s[i] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if two-digit decode is valid
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) {
                if (i >= 2)
                    dp[i] += dp[i - 2];
                else
                    dp[i] += 1;
            }
        }

        return dp[n - 1];
    }
};
