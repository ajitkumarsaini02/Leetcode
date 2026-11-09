class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& q) {
        int k = logs.size();
        int m = q.size();
        sort(logs.begin(), logs.end(), cmp);

        vector<pair<int, int>> queries(m);
        for (int i = 0; i < m; i++) {
            queries[i] = {q[i], i};
        }
        sort(queries.begin(), queries.end());

        int left = 0;
        int right = 0;

        int activeServer = 0;
        vector<int> ans(m);
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++) {
            int start = queries[i].first - x;
            int end = queries[i].first;
            int qIdx = queries[i].second;

            while (right < k && logs[right][1] <= end) {
                int sId = logs[right][0];
                if (mp[sId] == 0) {
                    activeServer++;
                }
                mp[sId]++;
                right++;
            }
            while (left < k && logs[left][1] < start) {
                int sId = logs[left][0];
                mp[sId]--;
                if (mp[sId] == 0) {
                    activeServer--;
                }
                left++;
            }
            ans[qIdx] = n - activeServer;
        }
        return ans;
    }
};