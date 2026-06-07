class Solution {
public:
    vector<vector<char>> digitVec = {
        {}, {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    void backtracking(int index, string& curr, string& digits, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        for (char ch : digitVec[digit]) {
            curr.push_back(ch);
            backtracking(index + 1, curr, digits, res);
            curr.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string curr;
        backtracking(0, curr, digits, res);
        return res;
    }
};
