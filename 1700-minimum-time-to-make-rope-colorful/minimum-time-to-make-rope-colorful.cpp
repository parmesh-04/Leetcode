class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cnt=0;
        for(int i=0;i<colors.size()-1;){
            if(colors[i]==colors[i+1]){
                int l=i;
                int mx=INT_MIN;
                while(l<colors.size() && colors[l]==colors[i]){
                    if(neededTime[l]>mx){
                        mx=neededTime[l];
                    }
                    cnt+=neededTime[l];
                    l++;
                }
                cnt-=mx;
                i=l;
            }else{
                i++;
            }
        }
        return cnt;
    }
};