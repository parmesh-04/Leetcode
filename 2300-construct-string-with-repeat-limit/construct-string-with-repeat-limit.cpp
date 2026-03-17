class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans;
        unordered_map<char,int> freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        priority_queue<char> pq;
        for(auto& [ch,cnt]: freq){
            pq.push(ch);
        }

        while(!pq.empty()){
            char c=pq.top();
            pq.pop();
            int cnt=min(repeatLimit,freq[c]);
            for(int i=0;i<cnt;i++){
                ans.push_back(c);
            }
            freq[c]=freq[c]-cnt;
            if(freq[c]>0 && !pq.empty()){
                char top=pq.top();
                pq.pop();
                ans.push_back(top);
                freq[top]--;
                if(freq[top]>0){
                    pq.push(top);
                }
                pq.push(c);
            }
        }
    return ans;
    }
};