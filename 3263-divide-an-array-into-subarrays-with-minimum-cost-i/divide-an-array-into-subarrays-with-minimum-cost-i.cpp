class Solution {
public:
    int minimumCost(vector<int>& nums){
        int m1=INT_MAX;
        int m2=INT_MAX;
        int cost=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<m1){
                m2=m1;
                m1=nums[i];
            }else if(nums[i]<m2){
                m2=nums[i];
            }
        }
        cost+=m1+m2;
        return cost;
    }
};