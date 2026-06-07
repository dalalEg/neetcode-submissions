 class Solution {
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, 
                                      {0, 1}, {0, -1}};


public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0,fresh=0;
        queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }
    
        while (!q.empty()&&fresh>0) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto& dir : directions) {
                    int nx = r + dir[0], ny = c + dir[1];
                    if (nx >= 0 && ny >= 0 && nx < ROWS && ny < COLS && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh==0 ?minutes:-1;
    }
};
