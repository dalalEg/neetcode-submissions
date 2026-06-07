#define ROWS 9
#define COLS 9

class Solution {
public:
    bool isValidSquare(vector<vector<char>>& board,int i,int j){
        //checking if the there is a digit which appears
        //more than just one time is the same square if yes then the sudoku is not valid
        if(i+3>ROWS || j+3>COLS)
            return true;
        vector<int> ans(10,0);
        for(int k=i;k<i+3;k++){
            for(int q=j;q<j+3;q++){
                char c=board[k][q];
                if(c!='.'){
                    int curr=c-'0';
                    if(ans[curr]==1)
                        return false;
                    ans[curr]=1;
                }
            }
        }
        bool b1=isValidSquare(board,i+3,j);
        bool b2=isValidSquare(board,i+3,j+3);
        bool b3=isValidSquare(board,i,j+3);
        return b1&&b2&&b3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //checking if the there is a digit which appears
        //more than just one time is the same row if yes then the sudoku is not valid
        for(int i=0;i<ROWS;i++){
            vector<int> ans(10,0);
            for(int j=0;j<COLS;j++){
                char c=board[i][j];
                if(c!='.'){
                    int curr=c-'0';
                    if(ans[curr]==1)
                        return false;
                    ans[curr]=1;
                }
            }
        }
        //checking if the there is a digit which appears
        //more than just one time is the same col if yes then the sudoku is not valid
        for(int i=0;i<COLS;i++){
            vector<int> ans(10,0);
            for(int j=0;j<ROWS;j++){
                char c=board[j][i];
                if(board[j][i]!='.'){
                    int curr=c-'0';
                    if(ans[curr]==1)
                        return false;
                    ans[curr]=1;
                }
            }
        }
        return isValidSquare(board,0,0);  
    }
};