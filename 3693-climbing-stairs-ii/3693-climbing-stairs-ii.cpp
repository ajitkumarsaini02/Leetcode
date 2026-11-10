class Solution {
public:
    vector<long long> dp;
    int climbStairs(int n, vector<int>& costs) {
        dp.resize(100005, INT_MAX);
        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 3; k++) {
                int i = j - k;
                if (i >= 0) {
                    long long cost = (long long)costs[j - 1] + 1LL * (j - i) * (j - i);
                    dp[j] = min(dp[j], dp[i] + cost);
                }
            }
        }
        return dp[n];
    }
};