class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();

        sort(arr2.begin(), arr2.end());

        int count = 0;
        for (int i = 0; i < arr1.size(); i++) {
            bool isValid = true;
            int low = 0;
            int high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (abs(arr2[mid] - arr1[i]) <= d) {
                    isValid = false;
                    break;
                } else if (arr2[mid] < arr1[i]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (isValid) {
                count++;
            }
        }
        return count;
    }
};