class Solution {
public:
    
    void solve(int idx,string& digits,unordered_map<char,string>& mp, string& temp,vector<string>& ans){
        
        if(idx==digits.length()){
            ans.push_back(temp);
            return;
        }

        char curr=digits[idx];
        for(char c: mp[curr]){
            temp.push_back(c);
            solve(idx+1,digits,mp,temp,ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }

        unordered_map<char,string> mp={
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
        };

        string temp;
        solve(0,digits,mp,temp,ans);
        return ans;
    }
};