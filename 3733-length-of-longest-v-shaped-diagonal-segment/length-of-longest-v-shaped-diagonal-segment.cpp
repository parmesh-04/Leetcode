class Solution {
public:
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n,m;

    int solve(int x, int y, int d, bool turn, int val,
              vector<vector<int>>& grid,
              vector<vector<vector<vector<int>>>>& dp) {
        int nx = x + dirs[d][0];
        int ny = y + dirs[d][1];
        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=val){
            return 0;
        }

        if(dp[nx][ny][d][turn]!=-1){
            return dp[nx][ny][d][turn];
        }
        int nt=0;
        if(val==0){
            nt=2;
        }

        int step=solve(nx,ny,d,turn,nt,grid,dp);
        if(turn){
            step=max(step,solve(nx,ny,(d+1)%4,0,nt,grid,dp));
        }

        return dp[nx][ny][d][turn]=step+1;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {

         n = grid.size();
         m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(4, vector<int>(2, -1))));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        ans = max(ans, solve(i, j, d, true, 2, grid, dp)+1) ;
                    }
                }
            }
        }

        return ans;
    }
};