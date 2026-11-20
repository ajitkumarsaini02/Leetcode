class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            int lo = 0;
            int hi = n - 1;
            int neg = n;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (grid[i][mid] < 0) {
                    neg = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            count += (n - neg);
        }
        return count;
    }
};