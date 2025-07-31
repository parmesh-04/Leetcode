class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int mx=nums[0];
       int sz=0;
       int ans=0;
       for(int i=0;i<nums.size();i++){
            if(mx<nums[i]){
                mx=nums[i];
                sz=1;
                ans=1;
            }else if(mx==nums[i]){
                sz++;
                ans=max(ans,sz);
            }else{
                    sz=0;
            }

       }
       return ans;
    }
};