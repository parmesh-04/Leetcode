class Solution {
public:

    bool solve(string& s,unordered_set<string>& st,vector<int>& dp,int idx){
        if(idx==s.length()){
            return true;
        }

        if(dp[idx]!=-1){
            return dp[idx]==1;
        }

        for(int i=idx+1; i<=s.length();i++){
            string temp=s.substr(idx,i-idx);
            if(st.count(temp)){
                if(solve(s,st,dp,i)){
                    dp[idx]=1;
                    return true;
                }
            }
        }   
        dp[idx]=0;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> dp(s.length(),-1);
        return solve(s,st,dp,0);
    }
};