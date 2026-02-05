class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int idx;
            if(nums[i]>0){
                idx=(i+nums[i])%n;
                ans[i]=nums[idx];
            }else if(nums[i]<0){
                idx=(n+(i-abs(nums[i]))%n)%n;
                ans[i]=nums[idx];
            }else{
                ans[i]=0;
            }
        }

        return ans;

    }
};