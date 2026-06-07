class Solution {
    int R, C;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited;

public:
    
    bool dfs(int x, int y,vector<vector<char>>& grid) {
        visited[x][y] = true;
        bool hasDirty = (grid[x][y] == '1');

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isValid(nx, ny,grid)) {
                grid[nx][ny]='0';
                hasDirty |= dfs(nx, ny, grid);
            }
        }

        return hasDirty;
    }

    bool isValid(int x, int y,vector<vector<char>>& grid) {
        return x >= 0 && x < R && y >= 0 && y < C &&
               (grid[x][y] == '1') && !visited[x][y];
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        R = grid.size(), C = grid[0].size();
        visited.assign(R, vector<bool>(C, false));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if ((grid[i][j] == '1') && !visited[i][j]) {
                    if (dfs(i, j,grid)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
