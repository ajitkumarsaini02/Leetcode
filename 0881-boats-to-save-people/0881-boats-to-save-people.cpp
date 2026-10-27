class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n = p.size();
        sort(p.begin(), p.end());

        int i = 0;
        int boats = 0;
        int j = n - 1;
        while (i <= j) {
            if (p[i] + p[j] <= limit) {
                boats++;
                i++;
                j--;
            } else {
                boats++;
                j--;
            }
        }
        return boats;
    }
};