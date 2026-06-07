class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            in_degree[pre[0]]++;
        }
        vector<int> res;

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int pre : adj[node]) {
                if (--in_degree[pre] == 0) {
                    q.push(pre);
                }
            }
        }
        return res.size() >= numCourses ? res : vector<int>();
    }
};
