class Solution {
public:

    struct comp{
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if(a[0]!=b[0]){
            return a[0]>b[0];
        }

        return a[1]>b[1];
    }
};
   

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        if(n<k){
            return {};
        }

        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            map<int,int> mp;
            int sum=0;

            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
                sum+=nums[j];
            }

            if(mp.size()<x){
               ans.push_back(sum);
               continue;
            }

            vector<vector<int>> v;
            for(auto& [ele,freq]:mp){
                v.push_back({freq,ele});
            }

            sort(v.begin(),v.end(),comp());
            int temp=0;
            for(int j=0;j<x;j++){
                temp+=v[j][0]*v[j][1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};