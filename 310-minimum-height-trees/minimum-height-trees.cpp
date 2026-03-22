class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>> adj(n);
        vector<int> d(n,0);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            d[e[0]]++;
            d[e[1]]++;
        }

    

        queue<int> q;
        for(int i=0;i<n;i++){
            if(d[i]==1){
                q.push(i);
            }
        }

        int rem=n;
        while(rem>2){
            int s=q.size();
            rem-=s;
            for(int i=0;i<s;i++){
                auto top=q.front();
                q.pop();
                for(int neigh: adj[top]){
                    d[neigh]--;
                    if(d[neigh]==1){
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

    return ans;
    }
};