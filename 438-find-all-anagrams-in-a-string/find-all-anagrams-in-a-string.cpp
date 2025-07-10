class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      unordered_map<char,int> wdw;
      unordered_map<char,int> mp;
      if(s.size()<p.size()){
        return {};
      }
      for(int i=0;i<p.size();i++){
         mp[p[i]]++;
         wdw[s[i]]++;
      }

      

      int l=0;
      int r=p.size()-1;
      vector<int> ans;
      while(true){
       bool flag=true;
      
        if(wdw.size()==mp.size()){
            for(auto [val,freq]:wdw){
                if(mp.find(val)==mp.end()){
                   flag=false;
                   break; 
                }else{
                    if(mp[val]!=wdw[val]){
                        flag=false;
                        break;
                    }
                }
            }

            
          
            if(flag){
                ans.push_back(l);
            }

        }

            wdw[s[l]]--;
            if(wdw[s[l]]==0){
                wdw.erase(s[l]);
            }
            l++; 
          
             r++;
             if(r==s.size()) break;
            wdw[s[r]]++;    
           

        
      }
      return ans;

    }
};