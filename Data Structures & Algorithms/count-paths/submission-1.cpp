class Solution {
public:
    vector<vector<int>> vc;
    int dfs(int i , int j,int m,int n ,vector<vector<int>>vc){
        if (i == (m - 1) && j == (n - 1)) {
            return 1;
        }
        if (i>=m || j>=n)
            return 0;
        if(vc[i][j]!=-1)
            return vc[i][j];
        vc[i][j]=dfs(i+1,j,m,n,vc)+dfs(i,j+1,m,n,vc);
        return vc[i][j];
    }
    int uniquePaths(int m, int n) {
        vc.resize(m, vector<int>(n, -1));
       
        return  dfs(0,0,m,n,vc);
    }
};
