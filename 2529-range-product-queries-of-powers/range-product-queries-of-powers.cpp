class Solution {
public:
 int MOD=1e9+7;
    int modExp(long long base,int exp){
       
        long long ans=1;
        base=base%MOD;
        while(exp>0){
            if(exp%2==1){
                ans=(ans*base)%MOD;
            }

            base=(base*base)%MOD;
            exp=exp/2;
        }
        return (int)ans;
    }


    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> prefix;
        int sum=0;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){
                sum+=i;
                prefix.push_back(sum);
            }
        }

        vector<int> ans;
        for(auto& q:queries){
           int exp;
          if(q[0]>0){
             exp=prefix[q[1]]-prefix[q[0]-1];
          }else{
            exp=prefix[q[1]];
          }

          ans.push_back(modExp(2,exp));
        }

        return ans;
    }
};