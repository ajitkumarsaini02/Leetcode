class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        int x = 10;
        while (n >= x) {
            n -= x;
            x--;
            if (x == 0) {
                break;
            }
        }

        return x % 2 == 1;
    }
};