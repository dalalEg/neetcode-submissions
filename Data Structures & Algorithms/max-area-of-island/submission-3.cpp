class Solution {
    int ROWS, COLS;
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= ROWS || j >= COLS || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int curr = 0;
        for (auto& dir : directions) {
            curr += dfs(i + dir[0], j + dir[1], grid);
        }
        return 1+curr;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        int res = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    res = max(res, dfs(i, j, grid));
                }
            }
        }
        return res;
    }
};
