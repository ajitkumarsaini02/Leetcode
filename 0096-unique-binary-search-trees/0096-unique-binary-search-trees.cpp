class Solution {
public:
    vector<int> dp;
    int numTrees(int n) {
        dp.clear();
        dp.resize(25, 0);
        dp[0] = dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] += dp[i-k] * dp[k-1];
            }
        }
        return dp[n];
    }
};