class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{row, col}, t}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});

                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for(int k = 0; k<4;k++){
                int nx = r + dx[k] ;
                int ny = c + dy[k];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 2 && grid[nx][ny] == 1){
                    q.push({{nx, ny}, t+1});
                    vis[nx][ny] = 2;
                }
            }
        }
        for(int i = 0 ;i<n;i++){
            for(int j = 0; j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1 )
                    return -1;
            }
        }
        return tm;
    }
};