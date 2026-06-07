class Solution {
    void dfs(int i,vector<int>& curr,int sum , vector<int>& candidates,int target){
        if( sum==target){
            res.push_back(curr);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(sum+candidates[j]>target || (j>i && candidates[j]==candidates[j-1]))
                continue;
            curr.push_back(candidates[j]);
            dfs(j+1,curr,sum+candidates[j],candidates,target);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        dfs(0, curr, 0, candidates, target);
        return res;
    }
};
