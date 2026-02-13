class Solution {
public:

    bool solve(string& s,int idx,string num1,string num2,int cnt){
        if(idx==s.length()) return cnt>=3;
        for(int i=idx;i<s.length();i++){
            if(i>idx && s[idx]=='0'){
                break;
            }
        

        string curr=s.substr(idx,i-idx+1);
        
        if(cnt>=2){
            string sum=add(num1,num2);
            if(curr==sum){
                if(solve(s,i+1,num2,curr,cnt+1)){
                    return true;
                }
            }else if(curr.length()>sum.length()){
            break;
        }}else{
            if(solve(s,i+1,num2,curr,cnt+1)){
                return true;
            }
        }
    }
    return false;
    }

    string add(string a,string b){
        string res="";
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0 || carry>0){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-'0';
                i--;
            }

            if(j>=0){
                sum+=b[j]-'0';
                j--;
            }
            carry=sum/10;
            res.push_back((sum%10)+'0');
        }
        reverse(res.begin(),res.end());
        return res;
    }

    bool isAdditiveNumber(string num) {
        return solve(num,0,"","",0);
    }
};