class Solution {
public:

    int solve(int idx, int diff,vector<int>& nums, vector<vector<int>>& dp){
        if(dp[idx][diff]!=-1) return dp[idx][diff];
        int len=1;
        for(int i=idx-1;i>=0;i--){
            if(nums[idx]-nums[i]+500==diff){
                len=1+solve(i,diff,nums,dp);
                break;
            }
        }
        return dp[idx][diff]=len;
    }

    int longestArithSeqLength(vector<int>& nums) {
            int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(1001,-1));
    
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j]+500;
                ans=max(ans,solve(i,diff,nums,dp));
            }
        }
        return ans;
    }
};