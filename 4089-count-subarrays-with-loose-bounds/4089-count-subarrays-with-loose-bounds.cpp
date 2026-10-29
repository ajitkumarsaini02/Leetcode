class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int j = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                ans += i - j + 1;
            } else {
                j = i + 1;
            }
        }
        return ans;
    }
};