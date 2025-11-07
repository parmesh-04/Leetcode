class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
       vector<vector<int>> adj(c+1);
        for(auto& e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

       map<int,set<int>> comp;
        vector<bool> visited(c+1,false);
        unordered_map<int,int> mp;

        for(int i=1;i<=c;i++){
            if(!visited[i]){
               
                queue<int> q;

                q.push(i);
                visited[i]=true;

                while(!q.empty()){
                    auto top=q.front();
                    q.pop();
                    mp[top]=i;
                    comp[i].insert(top);
                    for(auto neigh:adj[top]){
                        if(!visited[neigh]){
                            visited[neigh]=true;
                            q.push(neigh);
                        }
                    }
                }

               
            }
        }

      

       
        vector<int> ans;

        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                if(comp[mp[queries[i][1]]].empty()){
                    ans.push_back(-1);
                }else if(comp[mp[queries[i][1]]].count(queries[i][1])){
                    ans.push_back(queries[i][1]);
                }else{
                    ans.push_back(*comp[mp[queries[i][1]]].begin());
                }
            }else{
               comp[mp[queries[i][1]]].erase(queries[i][1]);
            }
        }

        return ans;

       
        
    }
};