class Solution {
public:
    bool isCompleteComponenent(int startNode, vector<vector<int>>& adj, vector<bool> & visited){
        int nodeCount = 0;
        int edgeCount = 0;

        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            nodeCount++;

            for(int neighbour : adj[curr]){
                if(curr == neighbour) return false;

                edgeCount++;

                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        int uniqueEdges = edgeCount/2;

        long long expectedEdges = (1LL * nodeCount * (nodeCount-1))/2;

        return uniqueEdges == expectedEdges;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        int count = 0;

        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i<n;i++){
            if(!visited[i]){
                if(isCompleteComponenent(i, adj, visited))
                    count++;
            }
        }
        return count;
    }
};