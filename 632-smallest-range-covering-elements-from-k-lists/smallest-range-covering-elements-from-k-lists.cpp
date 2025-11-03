class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>> v;
        if(nums.size()==1){
            return {nums[0][0],nums[0][0]};
        }
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j],i});
            }
        }
        sort(v.begin(),v.end());
        unordered_map<int,int> mp;
        vector<int> ans={-100000-1,100000+1};
        int l= 0;
        for(int i=0;i<v.size();i++){
            mp[v[i][1]]++;
            while(mp.size()==n && l<i){
                if((v[i][0]-v[l][0])<(ans[1]-ans[0])){
                    ans[0]=v[l][0];
                    ans[1]=v[i][0];
                }
                mp[v[l][1]]--;
                if(mp[v[l][1]]==0){
                    mp.erase(v[l][1]);
                }
                l++;
            }
        }
       return ans; 

    }
};