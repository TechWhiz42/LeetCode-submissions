class Solution {
private:
    bool bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{row, col}, {-1, -1}});
        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int pr = q.front().second.first;
            int pc = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == grid[r][c]) {

                    if (!vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.push({{nr, nc}, {r, c}});
                    }
                    else if (nr != pr || nc != pc) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (bfs(i, j, grid, vis))
                        return true;
                }
            }
        }

        return false;
    }
};