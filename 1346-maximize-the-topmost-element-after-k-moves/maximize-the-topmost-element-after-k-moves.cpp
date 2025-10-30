class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            if(n>0){
                return nums[0];
            }else{
                return -1;
            }
        }

        if(k==1){
            if(n<=1){
                return -1;
            }else{
                return nums[1];
            }
        }

        if(n==1){
            if(k%2==0){
                return nums[0];
            }else{
                return -1;
            }
        }

        int temp=min(k-1,n);
        int mx=0;
        for(int i=0;i<temp;i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
        }

        if(n>k){
            mx=max(mx,nums[k]);
        }

        return mx;
    }
};