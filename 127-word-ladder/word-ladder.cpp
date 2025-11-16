class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> st(wordList.begin(),wordList.end());
       if(!st.count(endWord)){
        return 0;
       }

       queue<string> q;
       q.push(beginWord);
       unordered_set<string> vis;
       vis.insert(beginWord);
       int cnt=1;
       while(!q.empty()){
         int sz=q.size();
         for(int i=0;i<sz;i++){
            string s=q.front();
            q.pop();
            if(s==endWord){
                return cnt;
            }

            for(int j=0;j<s.size();j++){
                string t=s;
                for(char k='a';k<='z';k++){
                    t[j]=k;
                    if(st.count(t) && !vis.count(t)){
                        q.push(t);
                        vis.insert(t);
                    }
                }
            }
            
         }
         cnt++;
       }

       return 0;

    }
};