class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (auto& a : apple) {
            totalApples += a;
        }

        sort(capacity.rbegin(), capacity.rend());

        int count = 0;
        for (int i = 0; i < capacity.size(); i++) {
            totalApples -= capacity[i];
            count++;
            if (totalApples <= 0) {
                return count;
            }
        }
        return count;
    }
};