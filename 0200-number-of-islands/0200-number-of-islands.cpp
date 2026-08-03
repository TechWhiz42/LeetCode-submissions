class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse in the neighbour if it's a land

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,-1,1};

            for(int k =0;k<4; k++){
                int nx = row + dx[k];
                int ny = col + dy[k];
                if(nx >= 0 && nx < n && ny >= 0 && ny <m && grid[nx][ny] == '1' && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for (int col = 0;col<m;col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt; 
    }
};