class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m,vector<int>(n,-1));
        for(int i=0;i<walls.size();i++){
            v[walls[i][0]][walls[i][1]]=1;
        }

        for(int i=0;i<guards.size();i++){
            v[guards[i][0]][guards[i][1]]=0;
        }

        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};

        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            for(int j=0;j<dir.size();j++){
                int nx=x+dir[j][0];
                int ny=y+dir[j][1];
                while(nx>=0 && nx<m && ny>=0 && ny<n && v[nx][ny]!=1 && v[nx][ny]!=0){
                        v[nx][ny]=2;
                        nx=nx+dir[j][0];
                        ny=ny+dir[j][1];
                    
                }
            }
        }

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==-1){
                    ans++;
                }
            }
        }
    return ans;

    }
};