class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int minSum = INT_MAX;

        for (int len = l; len <= r; len++) {
            int currSum = 0;

            for (int i = 0; i < len; i++) {
                currSum += nums[i];
            }

            if (currSum > 0) {
                minSum = min(minSum, currSum);
            }

            for (int i = len; i < n; i++) {
                currSum += nums[i] - nums[i - len];

                if (currSum > 0) {
                    minSum = min(minSum, currSum);
                }
            }
        }

        return (minSum == INT_MAX) ? -1 : minSum;
    }
};