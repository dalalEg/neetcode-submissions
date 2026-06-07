class Solution {
    int rows, cols;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited;
    bool dfs(int i, int j, vector<vector<char>>& board, vector < pair < int,int >> &curr) {
        visited[i][j] = true;
        curr.push_back({i,j});
        bool onBorder = (i != 0 && j != 0 && i != rows - 1 && j != cols - 1);
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols &&
                !visited[nx][ny] && board[nx][ny] == 'O')
                onBorder &= dfs(nx, ny, board, curr);
        }
        return onBorder;
    }

public:
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        visited.assign(rows, vector<bool>(cols, false));
        vector<vector<pair<int, int>>> vec;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    vector < pair < int, int >> curr;
                    if (dfs(i, j, board, curr)) {
                        vec.push_back(curr);
                    }
                }
            }
        }
        for(vector<pair<int, int>>& v:vec){
            for(auto& a:v){
                board[a.first][a.second]='X';
            }
        }
    }
};