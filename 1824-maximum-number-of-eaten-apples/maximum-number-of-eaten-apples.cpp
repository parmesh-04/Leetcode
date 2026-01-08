class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans=0;
        int n=apples.size();
        int i=0;
        while(!pq.empty() || i<n){
            if( i<n && apples[i]>0){
                pq.push({i+days[i],apples[i]});
            }
            while(!pq.empty() && pq.top().first<=i) pq.pop();
            if(!pq.empty()){
                auto top=pq.top();
                pq.pop();
                top.second--;
                ans++;
                if(top.second>0){
                    pq.push(top);
                }
            }

            i++;

        }

        return ans;
    }
};