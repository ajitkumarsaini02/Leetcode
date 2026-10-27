class Solution {
public:
    int getSign(int a, int b) {
        if (a > b) return 1;
        if (a < b) return -1;
        return 0;
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int maxLen = 1;
        int currLen = 1;
        int prevSign = 0;
        for (int i = 0; i < n - 1; i++) {
            int currSign = getSign(arr[i], arr[i + 1]);
            if (prevSign != 0 && currSign == -prevSign) {
                currLen++;
            } else if (currSign == 0) {
                currLen = 1;
            } else {
                currLen = 2;
            }

            maxLen = max(maxLen, currLen);
            prevSign = currSign;
        }
        return maxLen;
    }
};