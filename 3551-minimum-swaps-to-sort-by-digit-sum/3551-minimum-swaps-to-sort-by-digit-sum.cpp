class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            v[i] = {digitSum(nums[i]), nums[i]};
        }

        for (int i = 0; i < n; i++) {
            mp[v[i].second] = i;
        }

        vector<pair<int, int>> sorted = v;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; i++) {
            nums[mp[sorted[i].second]] = i;
        }
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
                swaps++;
            }
        }

        return swaps;
    }
};