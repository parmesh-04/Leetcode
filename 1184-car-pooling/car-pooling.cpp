class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector<int> v(1001,0);
       for(auto& t: trips){
         v[t[1]]+=t[0];
         v[t[2]]-=t[0];
       }

       int cnt=0;
       for(int i=0;i<1001;i++){
         cnt+=v[i];
         if(cnt>capacity){
            return false;
         }
       }
       return true;
    }
};