class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }

        unordered_map<int,vector<int>> mp;
        for(int i=0;i<routes.size();i++){
            for(int stop:routes[i]){
                mp[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visited;
        if(mp.count(source)){
            for(int idx: mp[source]){
                q.push(idx);
                visited.insert(idx);
            }
        }

        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int cr=q.front();
                q.pop();

            for(int stop: routes[cr]){
                    if(stop==target){
                        return ans;
                    }
            }

             for(int stop:routes[cr]){
                if(mp.count(stop)){
                    for(int next: mp[stop]){
                        if(visited.find(next)==visited.end()){
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }

            }

           

            ans++;

        }

        return -1;

    }
};