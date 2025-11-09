class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<vector<int>> v(profit.size(),vector<int>(2, 0));
        for(int i=0;i<profit.size();i++){
            v[i][0]=difficulty[i];
            v[i][1]=profit[i];
        }
        sort(v.begin(),v.end());

        int j=0;
        int mx=0;
        int ans=0;
        for(int i=0;i<worker.size();i++){
            while(j<v.size() && v[j][0]<=worker[i]){
                mx=max(mx,v[j][1]);
                j++;
            }
            ans+=mx;
        }

        return ans;
        
    }
};