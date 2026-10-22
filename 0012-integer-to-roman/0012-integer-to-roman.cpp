class Solution {
public:
    vector<int> digits(int n) {
        vector<int> digit;
        while (n > 0) {
            digit.push_back(n % 10);
            n /= 10;
        }
        reverse(digit.begin(), digit.end());
        return digit;
    }

    string intToRoman(int num) {
        unordered_map<int, char> mp;
        mp[1] = 'I';
        mp[5] = 'V';
        mp[10] = 'X';
        mp[50] = 'L';
        mp[100] = 'C';
        mp[500] = 'D';
        mp[1000] = 'M';

        string ans = "";
        vector<int> digit = digits(num);
        int n = digit.size();

        vector<int> unit = {1, 10, 100, 1000};

        for (int i = 0; i < n; i++) {
            int d = digit[i];
            int power = n - i - 1;
            int u = unit[power];

            if (d == 9) {
                ans += mp[u];
                ans +=  mp[u * 10];
            } else if (d >= 5) {
                ans += mp[u * 5];
                for (int j = 0; j < d - 5; j++) {
                    ans += mp[u];
                }
            } else if (d == 4) {
                ans += mp[u];
                ans += mp[u * 5];
            } else if (d > 0) {
                for (int j = 0; j < d; j++) {
                    ans += mp[u];
                }
            }
        }
        return ans;
    }
};