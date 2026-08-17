class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        for (auto& it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;
            for (int next : adj[node]) {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }
        return count == n;
    }
};