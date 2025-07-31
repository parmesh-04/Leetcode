class Solution {
public:

    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cst;
       
      
        for(int i=0;i<arr.size();i++){
            unordered_set<int> nxt;
          for(int ele : cst){
            nxt.insert(arr[i]|ele);
            ans.insert(arr[i]|ele);
          }

          nxt.insert(arr[i]);
          ans.insert(arr[i]);
          cst=nxt;
        }

        return ans.size();
    }
};