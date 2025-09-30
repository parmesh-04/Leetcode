class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1},   {-1, 0}, {0, -1},
                                      {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (grid[0][0] == 1) {
            return -1;
        }

        if (grid[r - 1][c - 1] == 1) {
            return -1;
        }

       
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        deque<pair<int, pair<int, int>>> q;
        dist[0][0] = 1;
        q.push_back({1, {0, 0}});
        while (!q.empty()) {
            auto top = q.front();
            q.pop_front();
            int i = top.second.first;
            int j = top.second.second;
            int cost = top.first;

            for (const auto& direction : directions) {
                int rr = i + direction[0];
                int cc = j + direction[1];

                if (rr >= 0 && rr < r && cc >= 0 && cc < c) {
                    if (grid[rr][cc] == 1)
                        continue;

                    if (dist[rr][cc] > cost + 1) {
                        dist[rr][cc] = cost + 1;
                        q.push_back({dist[rr][cc], {rr, cc}});
                    }
                }
            }
        }

        if (dist[r - 1][c - 1] == INT_MAX) {
            return -1;
        } else {
            return dist[r - 1][c - 1];
        }
    }
};