class Solution {
public:

    int solve(vector<int>& h){
        int n=h.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && h[st1.top()]>=h[i]){
                st1.pop();
            }
            if(!st1.empty()) nse[i]=st1.top();
            st1.push(i);
        }

        stack<int> st2;
         for(int i=0;i<n;i++){
        while(!st2.empty()&&h[st2.top()]>=h[i]){
            st2.pop();
        }
        if(!st2.empty()){
            pse[i]=st2.top();
        }
        st2.push(i);
       } 
       int area=0;
       for(int i=0;i<n;i++){
        area=max(area, (nse[i]-pse[i]-1)*h[i]);
       }
       return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> h(c,0); 
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
               if(matrix[i][j]=='1'){
                 h[j]+=1;
               }else{
                h[j]=0;
               }
            }
        ans=max(ans,solve(h));
        }
        return ans;
    }
};