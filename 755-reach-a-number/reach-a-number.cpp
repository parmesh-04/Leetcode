class Solution {
public:
    int reachNumber(int target) {
       long long sum=0;
       int ans=0;
       while(abs(target)>sum || (sum-abs(target))%2!=0){
        ans++;
        sum=sum+ans;
       
       }

       return ans;

    }
};