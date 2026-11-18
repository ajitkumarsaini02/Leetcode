class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n);

        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int ans = INT_MAX;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > leftMin[i - 1] && nums[i] > rightMin[i + 1]) {
                ans = min(ans, nums[i] + leftMin[i - 1] + rightMin[i + 1]);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};