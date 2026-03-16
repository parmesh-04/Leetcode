class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> h(c,0);
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    h[j]++;
                }else{
                    h[j]=0;
                }
            }
            vector<int> temp=h;
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0;j<c;j++){
                ans=max(ans,temp[j]*(j+1));
            }
        }
        return ans;
    }
};