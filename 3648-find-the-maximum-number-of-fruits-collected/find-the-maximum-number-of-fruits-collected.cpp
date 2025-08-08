class Solution {
public:
    int solve2( vector<vector<int>>& dp,vector<vector<int>>& fruits,int i,int j,int n){
         if (i>=n||i<0||j>=n||j<0) {
            return 0;
        }

        if(i>j||i==j){
            return 0;
        }

        if(i==n-1 && j==n-1){
            return 0;
        }

         if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int c1=fruits[i][j]+solve2(dp,fruits,i+1,j-1,n);
        int c2=fruits[i][j]+solve2(dp,fruits,i+1,j,n);
        int c3=fruits[i][j]+solve2(dp,fruits,i+1,j+1,n);
        return dp[i][j]=max({c1,c2,c3});


    }

     int solve3( vector<vector<int>>& dp,vector<vector<int>>& fruits,int i,int j,int n){
          if (i>=n||i<0||j>=n||j<0) {
            return 0;
        }

        if(i<j||i==j){
            return 0;
        }

          if(i==n-1 && j==n-1){
            return 0;
        }

         if(dp[i][j]!=-1){
            return dp[i][j];
        }

         int c1=fruits[i][j]+solve3(dp,fruits,i-1,j+1,n);
        int c2=fruits[i][j]+solve3(dp,fruits,i,j+1,n);
        int c3=fruits[i][j]+solve3(dp,fruits,i+1,j+1,n);
        return dp[i][j]=max({c1,c2,c3});

     }


    int maxCollectedFruits(vector<vector<int>>& fruits) {
       int n=fruits.size();
       int c=0;
       vector<vector<int>> dp2(n,vector<int>(n,-1));
        vector<vector<int>> dp3(n,vector<int>(n,-1));
       for(int i=0;i<n;i++){
        c+=fruits[i][i];
       
       }

       return c+solve2(dp2,fruits,0,n-1,n)+solve3(dp3,fruits,n-1,0,n); 
    }
};