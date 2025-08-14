class Solution {
public:
    string largestGoodInteger(string num) {
        char c='\0';
        for(int i=0;i<=num.size()-3;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                if(num[i]>c){
                    c=num[i];
                }
            }
        }
        if(c=='\0'){
            return "";
        }else{
            return string(3,c);
        }
    }
};