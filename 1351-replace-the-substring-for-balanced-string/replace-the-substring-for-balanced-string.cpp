class Solution {
public:
    int balancedString(string s) {
       unordered_map<char,int> mp;
       for(int i=0;i<s.size();i++){
            mp[s[i]]++;
       } 

       int ans=s.size();
       int cnt=s.size()/4;

    if (mp['Q'] <= cnt && mp['W'] <= cnt && mp['E'] <= cnt && mp['R'] <= cnt) {
    return 0;
}
      
       int l=0;
       for(int i=0;i<s.size();i++){
            mp[s[i]]--;
            while(l<=i && mp['Q']<=cnt && mp['R']<=cnt && mp['E']<=cnt && mp['W']<=cnt){
               ans=min(ans,i-l+1);
               mp[s[l]]++; 
               l++;
            }

       }
       return ans;
    }
};