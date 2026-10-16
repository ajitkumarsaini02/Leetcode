class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                prod *= (-1);
            } else if (nums[i] > 0) {
                prod *= 1;
            } else {
                return 0;
            }
        }
        if (prod < 0) return -1;
        else return 1;
    }
};