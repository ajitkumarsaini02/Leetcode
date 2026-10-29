class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();

        int maxFruits = 0;
        int currSum = 0;

        int j = 0;
        for (int i = 0; i < n; i++) {
            currSum += fruits[i][1];

            while (j <= i) {
                int ltr = abs(startPos - fruits[j][0]) + (fruits[i][0] - fruits[j][0]);
                int rtl = abs(fruits[i][0] - startPos) + (fruits[i][0] - fruits[j][0]);
                int totalSteps = min(ltr, rtl);

                if(totalSteps <= k){
                    break;
                }

                currSum -= fruits[j][1];
                j++;
            }
            maxFruits = max(maxFruits, currSum);
        }

        return maxFruits;
    }
};