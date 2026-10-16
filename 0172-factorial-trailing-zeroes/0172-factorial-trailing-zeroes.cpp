class Solution {
public:
    int trailingZeroes(int num) {
        int count = 0;
        int div = 5;
        while (true) {
            if(num / div == 0) break;
            count += num / div;
            div *= 5;
        }
        return count;
    }
};