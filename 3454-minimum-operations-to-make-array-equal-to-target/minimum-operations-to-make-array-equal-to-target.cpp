class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        for(int i=0;i<nums.size();i++){
            nums[i]=target[i]-nums[i];
        }

        long long ops=abs(nums[0]);
        

        for(int i=1;i<nums.size();i++){
          if((nums[i]>=0 && nums[i-1]<0) || (nums[i]<0 && nums[i-1]>=0)){
            ops+=abs(nums[i]);
            continue;
          }
        if(abs(nums[i])>abs(nums[i-1])){
            ops+=abs(nums[i])-abs(nums[i-1]);
        }

        }
        return ops;
    }
};