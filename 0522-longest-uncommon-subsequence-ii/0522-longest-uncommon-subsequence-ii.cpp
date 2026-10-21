class Solution {
public:
    bool isSubsequence(string& a, string& b) {
        int i = 0;
        int j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        string s = "";

        int maxLen = -1;
        for (int i = 0; i < n; i++) {
            bool check = false;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    check = true;
                    break;
                }
            }
            if (!check) maxLen = max(maxLen, (int)strs[i].size());
        }
        return maxLen;
    }
};