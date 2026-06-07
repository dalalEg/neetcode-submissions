class Solution {
    int rows,cols;
    set<pair<int, int>> path;
    bool check(int index,int i,int j,  vector<vector<char>>&board,string word){
         if (index == word.length()) {
            return true;
        }
       
        if(i<0||j<0||i>=rows||j>=cols|| board[i][j] != word[index] || path.count({i, j})) return false;
        path.insert({i,j});
        bool up =check(index+1,i+1,j,board, word);
        bool left=check(index+1,i,j-1,board, word);
        bool right=check(index+1,i,j+1,board, word);
        bool down =check(index+1,i-1,j,board, word);
         path.erase({i, j});

        return up||down||left||right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size(),cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(check(0,i,j,board,word))
                    return true;
            }
        }
        return false;
    }
};
