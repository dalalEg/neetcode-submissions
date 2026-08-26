class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>pre;
        vector<int> in_degree(numCourses,0);
        for (const auto& a: prerequisites){
            pre[a[0]].push_back(a[1]);
            in_degree[a[1]]+=1;
        }
        queue<int> q;
        for(int i =0; i < numCourses ;i++){
            if(in_degree[i]==0)
                q.push(i);
        }
        set<int> visited;
        while(q.size()){
            int curr = q.front();
            q.pop();
            visited.insert(curr);
            for(int n:pre[curr]){
                if(--in_degree[n]==0){
                    q.push(n);
                }
                
            }
        }
        return numCourses == visited.size();

    }
};
