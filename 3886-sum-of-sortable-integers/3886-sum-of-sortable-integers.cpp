class Solution {
public:
    bool isRotation(vector<int>& a, vector<int>& b, int start, int k) {
        for (int j = 0; j < k; j++) {
            if (a[(start + j) % k] != b[j])
                return false;
        }
        return true;
    }

    bool isAnyRotation(vector<int>& nums, int offset, vector<int>& sorted, int k) {
        vector<int>& pat = sorted;

        vector<int> fail(k, 0);
        for (int i = 1, j = 0; i < k; i++) {
            while (j > 0 && sorted[offset + i] != sorted[offset + j]) j = fail[j - 1];
            if (sorted[offset + i] == sorted[offset + j]) j++;
            fail[i] = j;
        }

        for (int i = 0, j = 0; i < 2 * k; i++) {
            int c = nums[offset + (i % k)];
            while (j > 0 && c != sorted[offset + j]) j = fail[j - 1];
            if (c == sorted[offset + j]) j++;
            if (j == k) return true;
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> div = nums;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int sum = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            for (int i = 0; i < n; i += k) {
                if (!isAnyRotation(div, i, sortedNums, k)) {
                    ok = false;
                    break;
                }
            }

            if (ok) sum += k;
        }

        return sum;
    }
};