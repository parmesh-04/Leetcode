class Solution {
public:
    int MOD=1e9+7;
    int solve(int n,int sum,int x,int num,vector<vector<int>>& dp){
        if(sum==n) return 1;
        int temp=pow(num,x);
        if(sum+temp>n) return 0;
        if(dp[num][sum]!=-1) return dp[num][sum];

        int take=solve(n,sum+temp,x,num+1,dp);
        int notTake=solve(n,sum,x,num+1,dp);
        return dp[num][sum]=(take+notTake)%MOD;

    }

    int numberOfWays(int n, int x) {
       vector<vector<int>> dp(301,vector<int>(301,-1));
       return solve(n,0,x,1,dp);
    }
};