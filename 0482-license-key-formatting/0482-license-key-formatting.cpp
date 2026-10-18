class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        int count = 0;
        string ans = "";

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (count > 0 && count % k == 0) {
                    ans += '-';
                }

                if (!isalpha(s[i])) {
                    ans += s[i];
                } else {
                    if (islower(s[i])) {
                        ans += toupper(s[i]);
                    } else {
                        ans += s[i];
                    }
                }
                count++;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};