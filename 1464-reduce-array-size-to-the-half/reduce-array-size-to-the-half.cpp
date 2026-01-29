class Solution {
public:
    int minSetSize(vector<int>& arr){ 
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        vector<int> v;
        for(auto & [ele,freq]: mp){
            v.push_back(freq);
        }

        sort(v.begin(),v.end(),greater<int>());

        int t=arr.size()/2;
        int s=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            s+=v[i];
            ans++;
            if(s>=t){
                break;
            }
        }
    return ans;
    }
};