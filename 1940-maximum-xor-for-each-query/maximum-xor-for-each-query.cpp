class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum^nums[i];
        }
    int n=nums.size();
    vector<int> ans;
       for(int i=n-1;i>=0;i--){
        ans.push_back(pow(2,maximumBit)-sum-1);
            sum=sum^nums[i];
       }
            
    return ans;
    }
};