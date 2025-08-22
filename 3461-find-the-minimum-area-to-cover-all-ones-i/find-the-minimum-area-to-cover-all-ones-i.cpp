class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int Xmin=INT_MAX;
        int Xmax=INT_MIN;
        int Ymin=INT_MAX;
        int Ymax=INT_MIN;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(i<Xmin){
                        Xmin=i;
                    }

                    if(i>Xmax){
                        Xmax=i;
                    }

                    if(j<Ymin){
                        Ymin=j;
                    }

                    if(j>Ymax){
                        Ymax=j;
                    }
                }
            }
        }

        return (Xmax-Xmin+1)*(Ymax-Ymin+1);

    }
};