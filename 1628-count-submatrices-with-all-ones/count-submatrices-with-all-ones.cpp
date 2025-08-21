class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        vector<int> h(n,0);

     
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (mat[i][j]==1) {
                    h[j]++; 
                } else {
                    h[j]=0; 
                }
            }
            for (int j=0;j<n;j++) {
                int mh=h[j];
                for (int k=j;k>=0;k--) {
                    if (h[k]==0) {
                        break; 
                    }
                    mh=min(mh,h[k]);
                    ans+=mh;
                }
            }
        }
    return ans;
    }
};