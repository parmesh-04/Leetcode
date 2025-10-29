class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        long long ans=0;
        long long cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && coins[j][1]<=coins[i][0]+k-1){
                cnt+=1LL*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }

            if(j<n){
               long long temp=1LL*max(0,coins[i][0]+k-1-coins[j][0]+1)*coins[j][2];
               ans=max(ans,cnt+temp);
            }
            cnt-=1LL*(coins[i][1]-coins[i][0]+1)*coins[i][2];
    }

    cnt=0;
    j=0;
    for(int i=0;i<n;i++){
        cnt+=1LL*(coins[i][1]-coins[i][0]+1)*coins[i][2];
        while(coins[j][1]<coins[i][1]-k+1){
            cnt-=1LL*(coins[j][1]-coins[j][0]+1)*coins[j][2];
            j++;
        }
        long long temp=1LL*max(0,coins[i][1]-k-coins[j][0]+1)*coins[j][2];
        ans=max(ans,cnt-temp);

    }
    return ans;
    }
};