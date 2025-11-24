class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==1){
                v1.push_back(nums[i]);
            }
            if(nums[i]%3==2) v2.push_back(nums[i]);
            sum+=nums[i];
        }

        if(sum%3==0) return sum;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int t1=0;
        int t2=0;
        
        if(sum%3==1){
            
            if(v1.size()>=1){
                t1=sum-v1[0];
            }

            if(v2.size()>=2){
                t2=sum-v2[0]-v2[1];
            }

            return max(t1,t2);

        }else{
             if(v2.size()>=1){
                t1=sum-v2[0];
            }

            if(v1.size()>=2){
                t2=sum-v1[0]-v1[1];
            }
            return max(t1,t2);
        }
    }
};