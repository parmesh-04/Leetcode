class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(),0);
        int s=0;
        int cnt=0;
        for(int i=0;i<boxes.size();i++){
             s+=cnt;
             ans[i]+=s;
            if(boxes[i]=='1'){
                cnt++;
            }

        }
        cnt=0;
        s=0;
        for(int i=boxes.size()-1;i>=0;i--){
            s+=cnt;
            ans[i]+=s;
            if(boxes[i]=='1'){
                cnt++;
            }
        }
        return ans;
    }
};