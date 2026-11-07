class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int x : nums) {
            max_or |= x;
        }

        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int x : nums) {
            unordered_map<int, int> next_dp = dp;
            for (auto& [mask, count] : dp) {
                next_dp[mask | x] += count;
            }
            dp = move(next_dp);
        }

        return dp[max_or];
    }
};