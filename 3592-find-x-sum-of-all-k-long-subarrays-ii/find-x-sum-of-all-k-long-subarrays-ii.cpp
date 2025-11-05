class Solution {
public:

    struct comp{
        bool operator()(const pair<int,int>& a,const pair<int,int>& b) const {
            if(a.first!=b.first){
                return a.first<b.first;
            }
            return a.second<b.second;
        }
    };


    void solve(int nw,int old,int x,unordered_map<int,int>& mp,set<pair<int,int>,comp>& top,set<pair<int,int>,comp>& oth,long long& sum){
        int ofreq=mp[old];
        if(top.count({ofreq,old})){
            top.erase({ofreq,old});
            sum-=(long long)old*ofreq;
        }else{
            oth.erase({ofreq,old});
        }

        mp[old]--;
        if(mp[old]>0){
            oth.insert({mp[old],old});
        }

        int nfreq=mp[nw];
        if(nfreq>0){
            if(top.count({nfreq,nw})){
                top.erase({nfreq,nw});
                sum-=(long long)nfreq*nw;

            }else{
                oth.erase({nfreq,nw});
            }
        }

        mp[nw]++;
        oth.insert({mp[nw],nw});

        while(top.size()<x && !oth.empty()){
            auto it=oth.rbegin();
            top.insert(*it);
            sum+=(long long)it->first*it->second;
            oth.erase(prev(oth.end()));
        }

        while(!top.empty() && !oth.empty() && *top.begin()<*oth.rbegin()){
            auto add=*oth.rbegin();
            auto rem=*top.begin();
            top.erase(rem);
            oth.erase(add);
            top.insert(add);
            oth.insert(rem);
            sum-=(long long)rem.first*rem.second;
            sum+=(long long)add.first*add.second;
        }
        
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<long long> ans;
        unordered_map<int,int> mp;
        set<pair<int,int>,comp> top;
        set<pair<int,int>,comp> oth;
        long long sum=0;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }

        for(auto& [num,freq]:mp){
            oth.insert({freq,num});
        }

        while(top.size()<x && !oth.empty()){
            auto it=oth.rbegin();
            top.insert(*it);
            sum+=(long long)it->first * it->second;
            oth.erase(prev(oth.end()));
        }
        ans.push_back(sum);
        for(int i=k;i<n;i++){
            solve(nums[i],nums[i-k],x,mp,top,oth,sum);
            ans.push_back(sum);
        }
        return ans;
    }
};