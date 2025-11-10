class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int x=1;
        int cnt=0;
        int i=0;
        while(x<=target){
            if(i<coins.size() && coins[i]<=x){
                x+=coins[i];
                i++;
            }else{
                x+=x;
                cnt++;
            }
        }
        return cnt;
    }
};