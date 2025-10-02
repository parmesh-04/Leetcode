class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int r,
              int c) {
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int val = 1;

        for (auto dir : directions) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                grid[nr][nc] > grid[r][c]) {
                val = max(val, 1 + solve(grid, dp, nr, nc));
            }
        }
        dp[r][c] = val;
        return val;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == -1) {
                    ans = max(ans, solve(matrix, dp, i, j));
                }
            }
        }
        return ans;
    }
};