class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        int m = INT_MAX;
        int n = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (a <= nums[i]) {
                c = b;
                b = a;
                a = nums[i];
            } else if (b < nums[i]) {
                c = b;
                b = nums[i];
            } else if(c < nums[i]){
                c = nums[i];
            }

            if(nums[i] <= m){
                n = m;
                m = nums[i];
            }
            else if(nums[i] < n){
                n = nums[i];
            }
        }
        return max(a * b * c, a * m * n);
    }
};