class Solution {
    vector<vector<string>> res;
   bool isSafe(int r, int c, vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtracking(int index,vector<string>&curr){
        if (index ==curr.size()) {
            res.push_back(curr);
            return;
        }
        for(int c=0 ; c<curr.size();c++){
            if (isSafe(index, c, curr)) {
                curr[index][c] = 'Q';
                backtracking(index + 1, curr);
                curr[index][c] = '.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(0,board);
        return res;
    }
};



