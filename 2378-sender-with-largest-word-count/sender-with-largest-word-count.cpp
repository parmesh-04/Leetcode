class Solution {
public:

    struct customComparator{
         bool operator()(const pair<string,int>& a,const pair<string,int>& b){
            if(a.second!=b.second){
                return a.second>b.second;
            }

            return a.first > b.first;
         }
    };
   

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        for(int i=0;i<senders.size();i++){
            string& s=messages[i];
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(s[j]==' ') cnt++;
            }
            mp[senders[i]]+=cnt+1;
        }

        vector<pair<string,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),customComparator());
        return v[0].first;
    }
};