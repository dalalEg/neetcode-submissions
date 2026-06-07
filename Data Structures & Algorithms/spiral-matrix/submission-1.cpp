class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int maxLine=0,buttomLine=matrix.size();
        int maxCol=matrix[0].size(),leftCol=0;
        vector<int> res;
        while(maxLine<buttomLine && maxCol>leftCol ){
            for(int i=leftCol;i<maxCol;i++)
                res.push_back(matrix[maxLine][i]);
            maxLine++;
            for(int i=maxLine;i<buttomLine;i++){
                res.push_back(matrix[i][maxCol-1]);
            }
            maxCol--;
            if (!(maxLine<buttomLine && maxCol>leftCol)) {
                break;
            }
            for(int i=maxCol-1;i>=leftCol;i--){
                res.push_back(matrix[buttomLine-1][i]);
            }
            buttomLine--;
            for(int i=buttomLine-1;i>=maxLine;i--){
                 res.push_back(matrix[i][leftCol]);
            }
            leftCol++;

        }
        return res;
    }
};
