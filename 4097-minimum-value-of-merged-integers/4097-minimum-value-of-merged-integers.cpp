class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        string s = "";
        for (int i = 0; i < n - 1; i += 2) {
            s += to_string(nums[i]);
            s += to_string(nums[i + 1]);

            ans = min(ans, stoi(s));
            s = "";
        }
        return ans;
    }
};