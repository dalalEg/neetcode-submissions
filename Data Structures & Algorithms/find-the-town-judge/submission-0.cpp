class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1,0),outdegree(n+1,0);
        for (auto& a : trust){
            indegree[a[1]]++;
            outdegree[a[0]]++;
        }
        for (int i=0;i<=n;i++){
            if (indegree[i]==n-1&&outdegree[i]==0){
                return i;
            }
        }
        return -1;
    }
};