class Solution {
public:
    int convertTime(string current, string correct) {
        int curMinutes = stoi(current.substr(0, 2)) * 60 + stoi(current.substr(3, 2));
        int corMinutes = stoi(correct.substr(0, 2)) * 60 + stoi(correct.substr(3, 2));
        
        int diff = corMinutes - curMinutes;
        int ans = 0;
        
        int ops[] = {60, 15, 5, 1};
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        
        return ans;
    }
};