class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        int firstDiff = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                firstDiff = i;
                break;
            }
        }

        int ans = 0;
        bool suffix = true;
        int diff = 0;
        unordered_map<int, int> mp;

        for (int i = n - 1; i >= 0; i--) {

            if (mp[nums[i]] == 0) {
                diff++;
            }
            mp[nums[i]]++;
            if (mp[nums[i]] == 0) {
                diff--;
            }

            if (mp[target[i]] == 0) {
                diff++;
            }
            mp[target[i]]--;
            if (mp[target[i]] == 0) {
                diff--;
            }

            if (i < n - 1 && target[i] < target[i + 1]) {
                suffix = false;
            }

            if (suffix && (i <= firstDiff) && diff == 0) {
                ans++;
            }
        }
        return ans;
    }
};