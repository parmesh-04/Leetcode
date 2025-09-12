class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> st = {'a','e','i','o','u'};
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(st.count(s[i])){
                cnt++;
            }
        }

        if(cnt==0){
            return false;
        }else{
            return true;
        }


    }
};