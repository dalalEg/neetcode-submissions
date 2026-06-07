class Solution {
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    vector<vector<int>> res;
    set<vector<int>> st;
    int ROWS,COLS;
    bool dfs(int i, int j,vector<vector<bool>>&visited, vector<vector<int>>& heights) {
        visited[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx >= 0 && ny >= 0 && nx < ROWS && ny < COLS) {
                if (!visited[nx][ny] && heights[nx][ny] >= heights[i][j]) {
                    dfs(nx, ny,visited, heights);
                }
            }
        }
        return true;  // optionally return nothing if not tracking conditions
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
