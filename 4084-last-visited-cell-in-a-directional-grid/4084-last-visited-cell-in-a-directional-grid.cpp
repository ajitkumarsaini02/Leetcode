class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int r = 0, c = 0;
        visited[0][0] = true;

        while (true) {
            int nr = r;
            int nc = c;

            char ch = grid[r][c];
            if (ch == 'L') nc--;
            else if (ch == 'U') nr--;
            else if (ch == 'R') nc++;
            else if (ch == 'D') nr++;

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc]) {
                break;
            }

            r = nr;
            c = nc;
            visited[r][c] = true;
        }
        return {r, c};
    }
};