class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v(2,0);
        int l=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            v[nums[i]]++;
            if(v[0]<=1){
                ans=max(ans,i-l+1);
            }else{
                while(v[0]>1){
                    v[nums[l]]--;
                    l++;
                }
            }

        }
        return ans-1;
    }
};