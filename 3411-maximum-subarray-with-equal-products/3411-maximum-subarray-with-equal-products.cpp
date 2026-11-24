class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        int maxLen = min(n, 2);
        int prod = 1;
        int j = 0;
        for (int i = 0; i < n; i++) {

            while (gcd(prod, nums[i]) > 1) {
                prod /= nums[j];
                j++;
            }

            prod *= nums[i];
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};