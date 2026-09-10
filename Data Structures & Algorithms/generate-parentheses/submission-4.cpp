class Solution {
    vector<string> res;
    void aux(int i, int n, string curr, int openP, int closeP) {
        if (i == 2 * n && openP == closeP) {
            res.push_back(curr);
            return;
        }
        if (i >= 2 * n || closeP > openP) {
            return;
        }

        aux(i + 1, n, curr + '(', openP + 1, closeP);
        aux(i + 1, n, curr + ')', openP, closeP+1);
    }

   public:
    vector<string> generateParenthesis(int n) {
        aux(0, n, "", 0, 0);
        return res;
    }
};
