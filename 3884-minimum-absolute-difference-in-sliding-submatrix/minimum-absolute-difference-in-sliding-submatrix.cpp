class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> ans(r-k+1,vector<int>(c-k+1,0));
        int p=r-k+1;
        int q=c-k+1;
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                vector<int> temp;
                for(int x=i;x<i+k;x++){
                    for(int y=j;y<j+k;y++){
                        temp.push_back(grid[x][y]);
                    }
                }
                 if(temp.size()<2){
                    ans[i][j]=0;
                    continue;
                }

                sort(temp.begin(),temp.end());
                int dif=INT_MAX;
                for(int t=1;t<temp.size();t++){
                    if(temp[t]-temp[t-1]==0){
                        continue;
                    }
                    dif=min(dif,temp[t]-temp[t-1]);
                    
                }
                if(dif==INT_MAX){
                    ans[i][j]=0;
                }else{
                    ans[i][j]=dif;
                }
                
            }
        }
return ans;
       
    }
};