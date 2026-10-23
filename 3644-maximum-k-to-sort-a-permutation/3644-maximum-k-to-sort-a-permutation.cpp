class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        bool isSorted = true;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                isSorted = false;
                if (ans == -1) {
                    ans = nums[i];
                } else {
                    ans &= nums[i];
                }
            }
        }
        if (isSorted) return 0;
        return ans;
    }
};