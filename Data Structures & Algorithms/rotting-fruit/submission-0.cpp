class Solution {
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, 
                                      {0, 1}, {0, -1}};

    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));
        visit[i][j] = true;
        int minutes = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                cout<<r<<" "<<c<<endl;
                q.pop();
                if (grid[r][c] == 2)
                    return minutes;
                for (auto& dir : directions) {
                    int nx = r + dir[0], ny = c + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < ROWS && ny < COLS &&
                        !visit[nx][ny] && grid[nx][ny]!=0) {
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        return -1;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = INT_MIN;
        ROWS = grid.size();
        COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    int minutes = bfs(i, j, grid);
                    if (minutes == -1)
                        return -1;
                    res = max(res, minutes);
                }
            }
        }
        return res==INT_MIN ?0:res;
    }
};
