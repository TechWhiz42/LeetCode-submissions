class Solution {
public:

    int ans = INT_MAX;
    void dfs(int node, vector<vector<pair<int,int>>>& graph, vector<bool>& vis){
        vis[node] = true;

        for(auto &[next, wt] : graph[node]){
            ans = min(ans, wt);
            if(!vis[next])
                dfs(next, graph, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto &r : roads){
            int u = r[0];
            int v = r[1];
            int w = r[2];

            graph[u].push_back({v,w});
            graph[v].push_back({u,w});

            
        }
        vector<bool> vis(n+1, false);
        dfs(1, graph, vis);
        return ans;
    }
};
