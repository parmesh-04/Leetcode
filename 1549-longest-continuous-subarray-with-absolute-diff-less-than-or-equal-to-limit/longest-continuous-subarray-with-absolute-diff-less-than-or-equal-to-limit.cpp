class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> mn;
        multiset<int,greater<int>> mx; 
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
           mn.insert(nums[i]);
           mx.insert(nums[i]);
         
            while(*mx.begin()-*mn.begin() > limit){
                auto it1=mx.find(nums[l]);
                auto it2=mn.find(nums[l]);
                mx.erase(it1);
                mn.erase(it2);
                l++;
            }
             ans=max(ans,i-l+1);
           
        }
        return ans;
    }
};