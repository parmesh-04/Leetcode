class Solution {
public:

    struct comp{
        bool operator()(const vector<int>& a, vector<int>& b) const{
            return a[1]<b[1];
        }
    };

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        int n=profit.size();
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(v.begin(),v.end(),comp());
          vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(v[i][1]);
        }
        vector<int> dp(n,-1);
        dp[0]=v[0][2];
        for(int i=1;i<n;i++){
            int take=v[i][2];
            int notTake=dp[i-1];
            auto it=upper_bound(temp.begin(),temp.begin()+i,v[i][0]);
            int idx=distance(temp.begin(),it)-1;

            if(idx>=0){
                take+=dp[idx];
            }

            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};