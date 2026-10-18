class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size();
        int m = version2.size();

        int i = 0;
        int j = 0;

        while (i < n || j < m) {
            string s1 = "";
            string s2 = "";
            while (i < n && version1[i] != '.') {
                s1 += version1[i];
                i++;
            }
            while (j < m && version2[j] != '.') {
                s2 += version2[j];
                j++;
            }
            int v1 = s1.empty() ? 0 : stoi(s1);
            int v2 = s2.empty() ? 0 : stoi(s2);

            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }

            if (i < n) i++;
            if (j < m) j++;
        }

        return 0;
    }
};