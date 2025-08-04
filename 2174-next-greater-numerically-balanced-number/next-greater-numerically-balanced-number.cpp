class Solution {
public:
int ans=INT_MAX;
int tn;

void np(string s,int len,vector<int>& d){
    if(s.size()==len){
        int num=stoi(s);
        if(num>tn){
            ans=min(ans,num);
        }
        return;
    }

    for(int i=1;i<=9;i++){
        if(d[i]>0){
            s.push_back(i+'0');
            d[i]--;
            np(s,len,d);
            d[i]++;
            s.pop_back();
        }
    }
}

void digitComb(int rem,int sd,vector<int>& d){
    if(rem==0){
      np("",accumulate(d.begin(),d.end(),0),d);
      return;
    }

    for(int i=sd;i<=9;i++){
        if(rem>=i){
            d[i]=i;
            digitComb(rem-i,i+1,d);
            d[i]=0;
        }

    }
}

    int nextBeautifulNumber(int n) {
        tn=n;
        for(int i=1;i<=7;i++){
            vector<int> d(10,0);
            digitComb(i,1,d);
        }
        return ans;
    }      
};