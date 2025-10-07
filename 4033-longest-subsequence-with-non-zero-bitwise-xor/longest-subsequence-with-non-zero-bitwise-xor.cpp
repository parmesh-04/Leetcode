class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum^nums[i];
        }

        if(sum!=0){
            return nums.size();
        }else{
            int cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    cnt++;
                }
            }

            if(cnt==nums.size()){
                return 0;
            }else{
                return nums.size()-1;
            }
        }
    }
};