class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }

        if(i==0 || i==n-1) return false;
        int t=i;
        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }

        if(i==t|| i==n-1) return false;

        t=i;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }

        if(i==t || i!=n-1) return false;

        return true;

    }
};