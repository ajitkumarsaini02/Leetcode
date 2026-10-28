class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;
        int currSum = 0;
        int j = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];

            while (st.count(nums[i])) {
                st.erase(nums[j]);
                currSum -= nums[j];
                j++;
            }

            st.insert(nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};