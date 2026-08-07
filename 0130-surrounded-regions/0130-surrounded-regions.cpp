class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nx = row + dx[k];
            int ny = col + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0 &&
                board[nx][ny] == 'O') {
                dfs(nx, ny, vis, board);
            }
        }
    }

public:
    vector<vector<char>> solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (board.empty())
            return board;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse rows
        // Traverse first and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, vis, board);

            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
                dfs(n - 1, j, vis, board);
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, vis, board);

            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
                dfs(i, m - 1, vis, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        return board;
    }
};