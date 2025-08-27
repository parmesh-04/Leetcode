class Solution {
public:
    int minOperations(int n) {
        int ans=0;
        for(int i=0;i<19;i++){
            if(!(n&1<<i)){
                continue;
            }else{
                if(n&1<<(i+1)){
                    n=n+(1<<i);
                }else{
                    n=n-(1<<i);
                }
                ans++;
            }


        }
        return ans;
    }
};