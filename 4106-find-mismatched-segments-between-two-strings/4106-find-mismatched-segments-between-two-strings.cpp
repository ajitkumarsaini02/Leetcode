class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();
        vector<vector<string>> ans;

        int i = 0;
        while (i < n) {
            if (s1[i] != s2[i]) {
                string a1 = "";
                string a2 = "";

                while (i < n && s1[i] != s2[i]) {
                    a1 += s1[i];
                    a2 += s2[i];
                    i++;
                }
                ans.push_back({a1, a2});
            } else {
                i++;
            }
        }
        return ans;
    }
};