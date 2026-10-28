class Solution {
public:
    using ll = long long;
    ll maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll maxSum = 0;
        ll currSum = 0;
        unordered_set<int> st;

        int j = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];

            while (st.count(nums[i])) {
                currSum -= nums[j];
                st.erase(nums[j]);
                j++;
            }

            st.insert(nums[i]);

            if (i - j + 1 > k) {
                currSum -= nums[j];
                st.erase(nums[j]);
                j++;
            }
            if (i - j + 1 == k) {
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }
};