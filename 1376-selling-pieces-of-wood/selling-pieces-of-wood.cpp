class Solution {
public:
    long long solve(int h, int w, vector<vector<long long>>& p, vector<vector<long long>>& dp){
        if(dp[h][w]!=-1){
            return dp[h][w];
        }

        long long profit=p[h][w];

        for(int i=1;i<=h/2;i++){
            profit=max(profit,solve(i,w,p,dp)+solve(h-i,w,p,dp));
        }

        for(int i=1;i<=w/2;i++){
            profit=max(profit,solve(h,i,p,dp)+solve(h,w-i,p,dp));
        }

        return dp[h][w]=profit;
    }


    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));
        vector<vector<long long>> p(m+1,vector<long long>(n+1,0));
        for(int i=0;i<prices.size();i++){
            p[prices[i][0]][prices[i][1]]=prices[i][2];
        }

        return solve(m,n,p,dp);

    }
};