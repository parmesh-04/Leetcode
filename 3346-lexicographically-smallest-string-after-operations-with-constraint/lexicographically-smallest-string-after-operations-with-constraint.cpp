class Solution {
public:
    string getSmallestString(string s, int k) {
     
      for(int i=0;i<s.size();i++){
        if(s[i]=='a') continue;
        if(min(s[i]-'a',26-(s[i]-'a'))<=k){
             k-=min(s[i]-'a',26-(s[i]-'a'));
            s[i]='a'; 
        }else{
            if(k>0){
                s[i]=s[i]-k;
                k=0;
            }
        }

      }
      return s;
    }
};