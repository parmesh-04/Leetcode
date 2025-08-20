class Solution {
public:
    int solve(int r,int c,vector<vector<int>>& matrix, vector<vector<int>>& dp ){
        if(r<0||c<0 || matrix[r][c]==0){
            return 0;
        }
        if(dp[r][c]!=-1) return dp[r][c];

        int a=solve(r-1,c,matrix,dp);
        int b=solve(r-1,c-1,matrix,dp);
        int d=solve(r,c-1,matrix,dp);
        return dp[r][c]=1+min({a,b,d});
       

    }

    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
      
        long long ans=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans+=solve(i,j,matrix,dp);
        }
       }
    return ans;
    }
};