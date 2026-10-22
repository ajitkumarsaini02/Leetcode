class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSeen = nums[0];
        int minSeen = nums[n - 1];
        int idx1 = -1;
        int idx2 = -1;

        for (int i = 1; i < n; i++) {
            maxSeen = max(maxSeen, nums[i]);
            if (maxSeen > nums[i]) {
                idx1 = i;
            }

            int d = n - i - 1;
            minSeen = min(minSeen, nums[d]);
            if (minSeen < nums[d]) {
                idx2 = d;
            }
        }
        if (idx1 == -1) return 0;
        return idx1 - idx2 + 1;
    }
};