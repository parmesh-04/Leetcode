 class DSU {
private:
   vector<int> parent;
   vector<int> sz;

public:
   
    DSU(int n) {
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0); 
     sz.assign(n + 1, 1);
    }

   
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
       
        return parent[i] = find(parent[i]);
    }

  
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
           
            if (sz[root_i] < sz[root_j]) {
               swap(root_i, root_j);
            }
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
        }
    }

    int getSize(){
        return sz.size();
    }

 };


class Solution {  
public:
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        DSU dsu(n);
        for(int i=0;i<nums.size();i++){
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    dsu.unite(nums[i],j);
                    dsu.unite(nums[i],nums[i]/j);
                }
            }
        }

        unordered_map<int,int> mp;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            int par=dsu.find(nums[i]);
          mp[par]++;
          ans=max(ans,mp[par]);  
        }

        return ans;

    }
};