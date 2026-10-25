
class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> prefix(n), suffix(n);
        unordered_set<char> st1, st2;

        for (int i = 0; i < n; i++) {
            st1.insert(s[i]);
            prefix[i] = st1.size();
        }

        for (int i = n - 1; i >= 0; i--) {
            st2.insert(s[i]);
            suffix[i] = st2.size();
        }

        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] == suffix[i + 1]) {
                count++;
            }
        }

        return count;
    }
};
