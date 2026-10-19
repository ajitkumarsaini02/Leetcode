/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int minIdx = INT_MAX;
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        int peak = low;
        // left array from peak
        low = 0;
        high = peak;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) == target) {
                minIdx = min(minIdx, mid);
                high = mid - 1;
            } else if (mountainArr.get(mid) < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // right array from peak
        low = peak;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) == target) {
                minIdx = min(minIdx, mid);
                high = mid - 1;
            } else if (mountainArr.get(mid) > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return minIdx == INT_MAX ? -1 : minIdx;
    }
};