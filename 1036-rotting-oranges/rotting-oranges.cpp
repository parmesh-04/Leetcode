class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        int r = grid.size();
        int c = grid[0].size();
        deque<pair<int, int>> rot;
        int n = grid.size();
        int cnt = 0;
        int cntRot = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2) {
                    rot.push_back({i, j});
                }

                if (grid[i][j] != 0) {
                    cnt++;
                }
            }
        }

        cntRot += rot.size();

        while (!rot.empty()) {
            int temp = rot.size();
            minute++;
            for (int i = 0; i < temp; i++) {
                pair<int, int> top = rot.front();
                rot.pop_front();
                int y = top.first;
                int x = top.second;

                if (x + 1 < c && grid[y][x + 1] == 1) {
                    grid[y][x + 1] = 2;
                    rot.push_back({y, x + 1});
                    cntRot++;
                }

                if (x - 1 >= 0 && grid[y][x - 1] == 1) {
                    grid[y][x - 1] = 2;
                    rot.push_back({y, x - 1});
                    cntRot++;
                }

                if (y + 1 < r && grid[y + 1][x] == 1) {
                    grid[y + 1][x] = 2;
                    rot.push_back({y + 1, x});
                    cntRot++;
                }

                if (y - 1 >= 0 && grid[y - 1][x] == 1) {
                    grid[y - 1][x] = 2;
                    rot.push_back({y - 1, x});
                    cntRot++;
                }
            }
        }

        if(cntRot<cnt){
            return -1;
        }else{
            return max(0,minute-1);
        }
    }
};