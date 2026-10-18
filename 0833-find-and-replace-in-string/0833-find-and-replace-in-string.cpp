class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();

        vector<int> matches(n, -1);
        for (int k = 0; k < indices.size(); k++) {
            int idx = indices[k];
            string src = sources[k];

            if (s.substr(idx, src.size()) == src) {
                matches[idx] = k;
            }
        }

        string ans = "";
        int i = 0;
        while (i < n) {
            if (matches[i] != -1) {
                int k = matches[i];
                ans += targets[k];
                i += sources[k].size();
            } else {
                ans += s[i];
                i++;
            }
        }
        
        return ans;
    }
};