class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int> mp;
      int m;
      for(int i=0;i<nums.size();i++){
        int num=nums[i];
        m=target-num;
        if(mp.find(m) !=mp.end()){
            return{mp[m],i};
        } 
        mp[num]=i;
      } 
      return {-1,-1}; 
    }
};