class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        int startHp = health - grid[0][0];

        if(startHp <= 0)
            return false;

        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(health + 1, false)));

        queue<tuple<int, int, int>> q;

        q.push({0,0,startHp});
        visited[0][0][startHp] = true;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty()){
            auto[r,c,h] = q.front();
            q.pop();

            if(r == m-1 && c == n-1)
                return true;

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                int newHp = h - grid[nr][nc];

                if(newHp <= 0 )
                    continue;

                if(!visited[nr][nc][newHp]){
                    visited[nr][nc][newHp] = true;
                    q.push({nr, nc, newHp});
                }
            }
        }
        return false;
    }
};
