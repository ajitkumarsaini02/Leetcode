class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = 0;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    sum += grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();

                        for (int d = 0; d < 4; d++) {
                            int nr = r + dx[d];
                            int nc = c + dy[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                grid[nr][nc]  > 0) {
                                
                                sum += grid[nr][nc];
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                                
                            }
                        }
                    }

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};