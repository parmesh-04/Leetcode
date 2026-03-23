class Solution {
public:

    int solve(int prev, int idx,vector<int>& nums, vector<vector<int>>& dp){
        if(idx>=nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int nt=solve(prev,idx+1,nums,dp);
        int t=0;
        if(prev==-1 || nums[idx]>nums[prev]){
            t=1+solve(idx,idx+1,nums,dp);
        }

        return dp[idx][prev+1]=max(t,nt);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(2501,vector<int>(2502,-1));
        return solve(-1,0,nums,dp);
    }
};