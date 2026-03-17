class Solution {
public:

    int MOD=1e9+7;

    int solve(vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp, int r, int c, int x){
        int m=grid.size();
        int n=grid[0].size();
      if(r>m-1 || c>n-1) return 0;
       
      if(r==m-1 && c==n-1){
        if((x^grid[r][c])==k) return 1;
        return 0;
      }

      if(dp[r][c][x]!=-1){
        return dp[r][c][x];
      }

      int down=solve(grid,k,dp,r+1,c,x^grid[r][c]);
      int right=solve(grid,k,dp,r,c+1,x^grid[r][c]);
      return dp[r][c][x]=(down+right)%MOD;

    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n, vector<int>(16,-1)));
        return solve(grid,k,dp,0,0,0);
    }
};