class Solution {
      vector<vector<int>> directions = {{1, 0}, {-1, 0}, 
                                      {0, 1}, {0, -1}};
    int rows,cols;
    const int LAND=INT_MAX;

    int bfs(int r,int c,vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        visit[r][c] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [row1, col1] = q.front();
                q.pop();
                if (grid[row1][col1] == 0) return steps;
                for (auto& dir : directions) {
                    int nr = row1 + dir[0], nc = col1 + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                        !visit[nr][nc] && grid[nr][nc] != -1) {
                        visit[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return LAND;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==LAND){
                    grid[i][j]=bfs(i,j,grid);
                }
            }
        }
    }
};
