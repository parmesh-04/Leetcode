class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        int ans=-1;
        for(auto& [val,freq]:mp){
            if(val==freq){
                ans=max(ans,val);
            }
        }
        return ans;
    }
};